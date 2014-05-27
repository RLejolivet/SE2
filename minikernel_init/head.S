/*
 *  mini kernel initialisation
 */


/*
 * High loaded stuff by Hans Lermen & Werner Almesberger, Feb. 1996
 */

#include "../include/config.h"
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
	movb $0xF8,%al		
	outb %al,$0x21		/* enable IRQ: +00,-01,+02,-03,-04,-05,-06,-07  */
	sti
	call init_processes
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
	cli
	pushl %eax
	pushl %ebx
	pushl %ecx
	pushl %edx


#if 0
 // Ce code a été abandonné parce qu'il fait tout planter et on sait pas pourquoi
	movl processes, %eax			# tableau des processus
	movl $(current_process), %ebx		# on récupère l'index du proc courant

	xor %ecx, %ecx
	cmpl %ebx, %ecx
	je 1f

	movl 0x24, %ecx				# 0x24 c'est la taille d'une task_struct
	imul %ecx, %ebx				# on veut connaitre l'offset par rapport au tableau
	add %ebx, %eax				# on avance pour pointer sur le task_struct courant

	movl (%eax), %ebx			# on met l'adresse de la TSS dans ebx
	movl 0x8(%ebx), %ecx			# si mes calculs sont bon, c'est ss_0
	shrl $0x10, %ecx			# on met ss_0 dans la partie basse de ecx
	movw %cx, %ss

	movl %esp, 0x14(%eax)			# si mes calculs sont bon, c'est pile_u
	movl 0x18(%eax), %esp			# si mes calculs sont bon, c'est pile_s
1:
#endif


	pushl %es
	pushl %ds
	pushl %fs
	pushl %gs

	movl $(__KERNEL_DS),%eax /* __KERNEL_DS = 0x18 */
	movl %eax,%ds
	movl %eax,%es
	movl %eax,%fs
	movl %eax,%gs

	call do_minikernel_irq0

	movb $0x20,%al
	outb %al,$0x20

	popl %gs
	popl %fs
	popl %ds
	popl %es


#if 0
 // Ce code a été abandonné parce qu'il fait tout planter et on sait pas pourquoi
	movl processes, %eax			# tableau des processus
	movl $(current_process), %ebx		# on récupère l'index du proc courant

	xor %ecx, %ecx
	cmpl %ebx, %ecx
	je 1f

	movl 0x24, %ecx				# 0x24 c'est la taille d'une task_struct
	imul %ecx, %ebx				# on veut connaitre l'offset par rapport au tableau
	add %ebx, %eax				# on avance pour pointer sur le task_struct courant

	
	movl (%eax), %ebx			# on met l'adresse de la TSS dans ebx
	movl 0x50(%ebx), %ecx			# si mes calculs sont bon, c'est ss
	shrl $0x10, %ecx			# on met ss_0 dans la partie basse de ecx
	movw %cx, %ss

	movl %esp, 0x18(%eax)			# si mes calculs sont bon, c'est pile_u
	movl 0x14(%eax), %esp			# si mes calculs sont bon, c'est pile_s
1:
#endif


	popl %edx
	popl %ecx
	popl %ebx
	popl %eax
	sti
	iret
	
.globl minikernel_irq1
minikernel_irq1:
	cld
	cli
	pushl %eax
	pushl %ebx
	pushl %ecx
	pushl %edx
	pushl %edi
	pushl %esi
	pushl %es
	pushl %ds
	pushl %fs
	pushl %gs

	movl $(__KERNEL_DS),%eax /* __KERNEL_DS = 0x18 */
	movl %eax,%ds
	movl %eax,%es
	movl %eax,%fs
	movl %eax,%gs

	xor %eax,%eax
	inb $0x60,%al

	pushl %eax
	call do_minikernel_irq1
	add $4,%esp
	movb $0x20,%al
	outb %al,$0x20

	popl %gs
	popl %fs
	popl %ds
	popl %es
	popl %esi
	popl %edi
	popl %edx
	popl %ecx
	popl %ebx
	popl %eax
	sti
	iret

#include "../include/exception_routines.h"
	
.globl minikernel_syscalls
minikernel_syscalls:
	cld
	pushl %ecx
	pushl %edx
	pushl %edi
	pushl %esi
	pushl %es
	pushl %ds
	pushl %fs
	pushl %gs
	pushl %ebx

	movl $(__KERNEL_DS),%ebx # __KERNEL_DS = 0x18
	movl %ebx,%ds
	movl %ebx,%es
	movl %eax,%fs
	movl %eax,%gs

	movl $0, %ebx
	cmpl %eax, %ebx
	je call_sys_sleep

	movl $0x1, %ebx
	cmpl %eax, %ebx
	je call_sys_write

	movl $0x2, %ebx
	cmpl %eax, %ebx
	je call_sys_read

	jmp call_kill_process

call_sys_sleep:
	call sys_sleep
	jmp end_minikernel_syscalls

call_sys_write:
	call sys_write
	jmp end_minikernel_syscalls

call_sys_read:
	call sys_read
	jmp end_minikernel_syscalls

call_kill_process:
	call kill_process
	jmp end_minikernel_syscalls # techniquement, si on revient ici, il y a un gros problème

end_minikernel_syscalls:
	popl %ebx
	popl %gs
	popl %fs
	popl %ds
	popl %es
	popl %esi
	popl %edi
	popl %edx
	popl %ecx
	iret
