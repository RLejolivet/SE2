#include <stdio.h>

void print_ignore_int_code();
void print_correct_idt();

main()
{
int i;
	/* generate the idt table */
	printf(".globl idt_table\n");
	printf("idt_table:\n");
	for (i=0 ; i<256 ; i++) {
		printf("\t.word interupt_%03d\n"
		       "\t.word 0x0010\n"
		       "\t.long interupt_%03d\n",
			i,i);
	}
	/* generate the interrupt routines */
	print_correct_idt();
	print_ignore_int_code();
	for (i=0 ; i<256 ; i++) {
		printf(     "\ninterupt_%03d:\n",i);
		printf("%s","\tpushl %eax\n",i);
		printf(     "\tmovl  $%d,%%eax\n",i);
		printf("%s","\tjmp   ignore_int\n");
	}
	
}

void print_correct_idt()
{
	printf("%s","\n");
	printf("%s",".globl interrupt_init\n");
	printf("%s","interrupt_init:\n");
	printf("%s","	movl  $idt_table+4,%edi\n");
	printf("%s","1:	cmpl  $idt_table+256*8+4,%edi\n");
	printf("%s","	jz    2f\n");
	printf("%s","	movw  $0x8e00,(%edi)\n");
	printf("%s","	addl  $8,%edi\n");
	printf("%s","	jmp   1b\n");
	printf("%s","2:	lidt idt_descr\n");
	printf("%s","	ret\n");
}

void print_ignore_int_code()
{
	printf("%s","\n");
	printf("%s","ignore_int_mess:\n");
	printf("%s","	.asciz \"interrupt \%03d (0x%02x) is ignored\\n\"\n");
	printf("%s","	.align\n");
	printf("%s","ignore_int:\n");
	printf("%s","	cld\n");
	printf("%s","	pushl %ecx\n");
	printf("%s","	pushl %edx\n");
	printf("%s","	pushl %es\n");
	printf("%s","	pushl %ds\n");
	printf("%s","	movl  $(__KERNEL_DS),%ecx\n");
	printf("%s","	movl  %ecx,%ds\n");
	printf("%s","	movl  %ecx,%es\n");
	printf("%s","	pushl %eax\n");
	printf("%s","	pushl %eax\n");
	printf("%s","	pushl $ignore_int_mess\n");
	printf("%s","	pushl $sc_kernel\n");
	printf("%s","	call  SYMBOL_NAME(kprintf)\n");
	printf("%s","	addl  $16,%esp\n");
	printf("%s","	popl  %ds\n");
	printf("%s","	popl  %es\n");
	printf("%s","	popl  %edx\n");
	printf("%s","	popl  %ecx\n");
	printf("%s","	popl  %eax\n");
	printf("%s","	iret\n");
}
