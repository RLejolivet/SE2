#include "libc.h"
int j= 0x11111111;

int i= 0x22222222;

int test42(int k){
	i=52;
	j=44;
	return 0;
}
int main()
{
	char tab[50];
	char c;
	i=5;
	write(i) ;
	scanf("%c %s", &c, tab);
	write(c);
	write('\n');
	sleep(5);
	write(i);
	while(1) {
		sleep(1);
		write(3);
	}
}
