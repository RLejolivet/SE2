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
	i = 0x42;
	write(i) ;
	while(1) {
		/*asm volatile ("movb $0x20, %%al\n\t"
			      "outb %%al, $0x20\n\t"
			      "sti\n\t":::"eax");*/
		sleep(1);
	}
}
