.global function_test
function_test:
	movl $0, %eax
	movl $0x14, %ebx
	int $0x80
	
	xor %ebx, %ebx
	movl $0x41, %ebx
	movl $1, %eax
	int $0x80

	movl $2, %eax
	int $0x80

	movl $3, %eax
	int $0x80
	ret
