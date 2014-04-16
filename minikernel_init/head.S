/*
 *  mini kernel initialisation
 */


/*
 * High loaded stuff by Hans Lermen & Werner Almesberger, Feb. 1996
 */

#include <config.h>
.text
.globl startup_32
.globl idt_table

startup_32:
	cld
	cli
	movl $(__KERNEL_DS),%eax
	movl %eax,%ss
	movl %eax,%ds
	movl %eax,%es
	movl %eax,%fs
	movl %eax,%gs

	movl $stack_end,%esp
	xorl %eax,%eax
1:	incl %eax		# check that A20 really IS enabled
	movl %eax,0x000000	# loop forever if it isn't
	cmpl %eax,0x100000
	je 1b
/*
 * Initialize eflags.  Some BIOS's leave bits like NT set.  This would
 * confuse the debugger if this code is traced.
 * XXX - best to initialize before switching to protected mode.
 */
	pushl $0
	popfl
/*
 * Clear BSS
 */
	xorl %eax,%eax
	movl $ SYMBOL_NAME(_edata),%edi
	movl $ SYMBOL_NAME(_end),%ecx
	subl %edi,%ecx
	cld
	rep
	stosb
/*
 * Launch the mini kernel
 */
	call interrupt_init
	call vga_init
	call ttyS_init
	call main_init
	movb $0xFF,%al
	outb %al,$0xa1		/* enable IRQ: -8,-9,-10,-11,-12,-13,-14,-15 */
	movb $0xFA,%al
	outb %al,$0x21		/* enable IRQ: +00,-01,+02,-03,-04,-05,-06,-07  */
	sti
	call mini_kernel
1:	
	jmp 1b

/******** memory for stack ********/
.org 0x1000
stack:
.org 0x2000
stack_end:

/******** interrupt table ********/
#include "idt.h"
idt_descr:
	.word 256*8-1		/* idt_table contains 256 entries */
	.long idt_table

/******** irq entries     ********/
.globl minikernel_irq0
minikernel_irq0:
	cld
	pushl %eax
	pushl %ecx
	pushl %edx
	pushl %es
	pushl %ds
	movl $(__KERNEL_DS),%eax
	movl %eax,%ds
	movl %eax,%es
	call do_minikernel_irq0
	movb $0x20,%al
	outb %al,$0x20
	popl %ds
	popl %es
	popl %edx
	popl %ecx
	popl %eax
	iret
	
