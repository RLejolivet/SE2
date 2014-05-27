#include "libc.h"
int j= 0x11111111;

int i= 0x22222222;

int test42(){
	i=52;
	j=44;
	return 0;
}
int main()
{
	i=5;
	test42();
	i = 0x43;
	write(i) ;
	//asm volatile("movl 0x3, %%eax\n\tint $0x80":::"eax");
	while(1) {sleep(1);
	}
}
