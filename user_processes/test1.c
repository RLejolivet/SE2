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
	i = 0x41;
	printf("test numero 52 %c\n", i) ;
	write(i) ;
	while(1) {
		sleep(5);
		write(i);
	}
}
