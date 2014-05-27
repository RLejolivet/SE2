#include "libc.h"

int main()
{
	int i=0, j;
	while(1)
	{
		for(j=0;j<=i;j++)
		{
			write(5);
		}
		write('\n');
		sleep(1);
		i = (i+1) % 10;
	}
}
