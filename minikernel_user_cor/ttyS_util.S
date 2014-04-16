
.text

.globl	ttyS_config
.globl	ttyS_config_interrupt
.globl	ttyS_write
.globl	ttyS_read
.globl	minikernel_irq4

ttyS_config:
	pushl %ebx
	pushl %ecx
	pushl %edx
	pushl %edi
	movl  16+4(%esp),%edi	/* base address (first C parameter)*/
	movl  16+8(%esp),%ebx	/* baud (second C parameter)       */

	movw %di,%dx		/* no interrupt */
	addw $1,%dx
	movb $0x00,%al
	outb %al,%dx

	movb $0x80,%al		/* set baud */
	movw %di,%dx
	addw $3,%dx
	outb %al,%dx		/* set msb of LCR */
	movw %di,%dx
	movw %bx,%ax
	outw %ax,%dx		/* baud register when msb of LCR is 1 */

	movb $0x3,%al		/* 3: 8 bits, no parity, 2 stop bits  */
	movw %di,%dx
	addw $3,%dx			/* dx is set to LCR address (base+3)  */
	outb %al,%dx

	xor %al,%al
	movw %di,%dx
	addw $2,%dx			/*  dx is set to  base + 2 (FCR) */
	outb %al,%dx		/* 0: no fifos                   */

	movw %di,%dx
	addw $4,%dx		/* dx is set to  base + 4 (MCR) */
	xor %al,%al     /* 0: no llopback, no special lines */
	outb %al,%dx

	popl %edi
	popl %edx
	popl %ecx
	popl %ebx
	ret

ttyS_config_interrupt:
	pushl %ebx
	pushl %ecx
	pushl %edx
	pushl %edi
	movl  16+4(%esp),%edi	/* base address (first C parameter)*/
	movl  16+8(%esp),%ebx	/* baud (second C parameter)       */

	movw %di,%dx		/* interrupt when THR empty and RSR full */
	addw $1,%dx
	movb $0x01,%al
	outb %al,%dx

	movw %di,%dx
	addw $4,%dx		/* dx is set to  base + 4 (MCR) */
	movb $0x0C,%al  /* intrupt enable, no llopback, no special lines */
	outb %al,%dx

	movb $0xEA,%al
	outb %al,$0x21		/* enable IRQ: +00,-01,+02,-03,+04,-05,-06,-07  */

	popl %edi
	popl %edx
	popl %ecx
	popl %ebx
	ret

ttyS_write:
	pushl %edi
	pushl %edx
	pushl %ebx
	movl  12+4(%esp),%edi	/* base address (first parameter) */
	movl  %edi,%edx		/* LSR (Line status register) */
	addw  $5,%dx
1:
	inb   %dx,%al		/* bit 5 to 1 indicates ready to transmit */
	testb $0x20,%al
	jz    1b
	
	movl  12+8(%esp),%eax	/* char to send (second parameter) */
	movw  %di,%dx
	outb  %al,%dx		/* write to THR */

	popl %ebx
	popl %edx
	popl %edi
	ret

ttyS_read:
	pushl %edi
	pushl %edx
	pushl %ebx
	movl  12+4(%esp),%edi	/* base address (first parameter) */
	movl  %edi,%edx		/* LSR (Line status register) */
	addw  $5,%dx
1:
	inb   %dx,%al		/* bit 0 to 1 indicates RSR is full */
	testb $0x01,%al
	jz    1b
	
	xorl  %eax,%eax
	movw  %di,%dx
	inb   %dx,%al		/* read to RSR */

	popl  %ebx
	popl  %edx
	popl  %edi
	ret

/* called when a data is present in RBR */
minikernel_irq4:
	cld
	pushl %eax
	pushl %ebx
	pushl %ecx
	pushl %edx

//	inb   $0x21,%al
//	orb   $0x10,%al
//	outb   %al,$0x21
	movb  $0x20,%al
	outb  %al,$0x20

	xor   %eax,%eax
	movw  $0x3fA,%dx
	inb   %dx,%al
	testb  $1,%al
	jnz   1f
	movw  $0x3f8,%dx
	inb   %dx,%al
	pushl %eax
	call do_minikernel_irq4
	addl $4,%esp

1:
//	inb   $0x21,%al
//	andb  $0xef,%al
//	outb   %al,$0x21
	popl %edx
	popl %ecx
	popl %ebx
	popl %eax
	iret
	
