.globl minikernel_exception0 
 minikernel_exception0: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception0 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception1 
 minikernel_exception1: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception1 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception2 
 minikernel_exception2: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception2 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception3 
 minikernel_exception3: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception3 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception4 
 minikernel_exception4: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception4 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception5 
 minikernel_exception5: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception5 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception6 
 minikernel_exception6: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception6 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception7 
 minikernel_exception7: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception7 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception8 
 minikernel_exception8: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception8 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception9 
 minikernel_exception9: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception9 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception10 
 minikernel_exception10: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception10 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception11 
 minikernel_exception11: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception11 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception12 
 minikernel_exception12: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception12 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception13 
 minikernel_exception13: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception13 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception14 
 minikernel_exception14: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception14 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception15 
 minikernel_exception15: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception15 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception16 
 minikernel_exception16: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception16 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception17 
 minikernel_exception17: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception17 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception18 
 minikernel_exception18: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception18 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception19 
 minikernel_exception19: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception19 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception20 
 minikernel_exception20: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception20 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception21 
 minikernel_exception21: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception21 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception22 
 minikernel_exception22: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception22 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception23 
 minikernel_exception23: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception23 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception24 
 minikernel_exception24: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception24 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception25 
 minikernel_exception25: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception25 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception26 
 minikernel_exception26: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception26 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception27 
 minikernel_exception27: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception27 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception28 
 minikernel_exception28: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception28 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception29 
 minikernel_exception29: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception29 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception30 
 minikernel_exception30: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception30 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 iret



 
 .globl minikernel_exception31 
 minikernel_exception31: 
 cld 
 cli 
 pusha 
 pushl %ds 
 pushl %es 
 pushl %ss 
 pushl %esi 
 pushl %edi 
 movl $(0x18),%eax 
 ljmp $(0x10),$1f 
 1: 
 movl %eax,%ds 
 movl %eax,%es 
 call handle_exception31 
 movb $0x20,%al 
 outb %al,$0x20 
 popl %edi 
 popl %esi 
 popl %ss 
 popl %es 
 popl %ds 
 popa 
 sti 
 ret
