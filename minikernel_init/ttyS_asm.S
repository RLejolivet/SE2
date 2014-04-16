.text
.globl	ttyS_detect
.globl	ttyS_getIrq
.globl	uart_name
.globl	ttyS0_base
.globl	ttyS1_base

uart_name:	.fill 64
ttyS0_base:	.word 0
ttyS1_base:	.word 0
	
uart_8250_name:		.asciz "uart8250"
uart_16450_name:	.asciz "uart16450"
uart_16550_name:	.asciz "uart16550"
uart_16550A_name:	.asciz "uart16550A"

ttyS_detect:
	xorl  %eax,%eax
	push  %ebx
	movl  8(%esp),%ebx	/* bx is the base addr of the uar,   */
	                    /* get it from the stack             */
	push  %edx
	/**** Is there an UART ? ****/
	movw  %bx,%dx		/* write MCR (modem control register */
	addw  $4,%dx		/* address base+4)                   */
	movb  $0x10,%al		/* set the loopback mode             */
	outb  %al,%dx
	outb  %al,$0x80
	movw  %bx,%dx		/* read MSR (modem status register   */
	addw  $6,%dx		/* address base+6)                   */
	inb   %dx,%al
	outb  %al,$0x80
	testb $0xF0,%al		/* must be == 0 */
	jnz   no_uart

	movw  %bx,%dx		/* write MCR (modem control register */
	addw  $4,%dx		/* address base+4)                   */
	movb  $0x1f,%al		/* set the loopback mode             */
	outb  %al,%dx
	outb  %al,$0x80
	movw  %bx,%dx		/* read MSR (modem status register   */
	addw  $6,%dx		/* address base+6)                   */
	inb   %dx,%al
	outb  %al,$0x80
	andb  $0xf0,%al
	cmpb  $0xF0,%al		/* must be == 0xf0 */
	jnz   no_uart

	/*** the scratch register does'nt exist on  8250 uart ***/
	movw  %bx,%dx		/* write SCR (scratch register       */
	addw  $7,%dx		/* address base+7)                   */
	movb  $0xab,%al
	outb  %al,%dx
	outb  %al,$0x80
	inb   %dx,%al		/* reread SCR (scratch register)     */
	outb  %al,$0x80
	cmpb  $0xab,%al		/* must be != for 8250 uart          */
	jz    no_8250_uart
	movb  $0xba,%al		/* same with 0xba to be sure         */
	outb  %al,%dx
	outb  %al,$0x80
	inb   %dx,%al
	outb  %al,$0x80
	cmpb  $0xba,%al
	jz    no_8250_uart
	pushl $uart_8250_name
	call  ttyS_set_uart_name
	addl  $4,%esp
	movl  $1,%eax
	jmp   fin

no_8250_uart:
	/*** check if there is fifos ***/
	movw  %bx,%dx		/* write FCR (fifo contol register   */
	addw  $2,%dx		/* address base+2)                   */
	movb  $0x01,%al		/* set fifo enable                   */
	outb  %al,%dx
	outb  %al,$0x80
	inb   %dx,%al		/* read IIR (fifo & interrupt status */
	outb  %al,$0x80		/* register, address base+2)         */
	testb  $0x80,%al
	jnz   no_16450_uart
	pushl $uart_16450_name
	call  ttyS_set_uart_name
	addl  $4,%esp
	movl  $2,%eax
	jmp   fin

no_16450_uart:
	testb  $0x40,%al
	jnz   no_16550_uart
	pushl $uart_16550_name
	call  ttyS_set_uart_name
	addl  $4,%esp
	movl  $3,%eax
	jmp   fin

no_16550_uart:
	pushl $uart_16550A_name
	call  ttyS_set_uart_name
	addl  $4,%esp
	movl  $4,%eax
	jmp   fin

no_uart:
	xorl  %eax,%eax
fin:
	popl %edx
	popl %ebx
	ret

tty_mask_m: .byte	0
tty_mask_s: .byte	0
tty_irq_m:  .byte	0
tty_irq_s:  .byte	0

ttyS_getIrq:
	xorl  %eax,%eax
	push  %ebx
	movl  8(%esp),%ebx	/* bx is the base addr of the uar,   */
	                    	/* get it from the stack             */
	push  %edx


	movw  %bx,%dx		/* write 0 --> IER  */
	addw  $1,%dx		
	xorb  %al,%al		
	outb  %al,%dx

1:
	movw  %bx,%dx		/* while THR not empty */
	addw  $5,%dx		
	inb   %dx,%al
	test  $0x20,%al
	jz   1b

	movw  %bx,%dx
	addw  $4,%dx
	movb  $0x0f,%al
	outb  %al,%dx
	
	movb  $0x0A,%al
	outb  %al,$0xA0     /* next read access to 0xA0 out IRR */
	outb  %al,$0x20		/* next read access to 0x20 out IRR */

	movw  %bx,%dx		/* let's generate an interrupt */
	addw  $1,%dx		
	movb  $2,%al
	outb  %al,%dx
	
	inb   $0x20,%al
	movb  %al,tty_mask_m
	inb   $0xA0,%al
	movb  %al,tty_mask_s

	movw  %bx,%dx		/* drop the interrupt line     */
	addw  $1,%dx		
	movb  $0,%al
	outb  %al,%dx
	
	inb   $0x20,%al
	not   %al
	andb  %al,tty_mask_m
	inb   $0xA0,%al
	not   %al
	andb  %al,tty_mask_s
	
	movw  %bx,%dx		/* raise it again just to be sure */
	addw  $1,%dx		
	movb  $2,%al
	outb  %al,%dx
	
	inb   $0x20,%al
	andb  %al,tty_mask_m
	inb   $0xA0,%al
	andb  %al,tty_mask_s
	
	movb  tty_mask_s,%al /* now let's umask umask this interrupt only */
	not   %al
	outb  %al,$0xA1
	movb  tty_mask_m,%al
	not   %al
	outb  %al,$0x21

	movb  $0x0c,%al
	outb  %al,$0xA0
	outb  %al,$0x20

	inb   $0xA0,%al
	movb  %al, tty_irq_s
	inb   $0x20,%al
	movb  %al, tty_irq_m

	movw  %bx,%dx		/* reset transmitter interrupt in UART */
	addw  $2,%dx		
	inb   %dx,%al		

	testb $0xff,tty_mask_s	/* send an EOI to slave if needed */
	jz    1f
	movb  0x20,%al
	outb  %al,$0xA0
1:	testb $0xff,tty_mask_m  /* send an EOI to slave if needed */
	jz    1f
	movb  0x20,%al
	outb  %al,$0x20
1:
	movb tty_irq_s,%al
	movb tty_irq_m,%ah

	popl %edx
	popl %ebx
	ret

