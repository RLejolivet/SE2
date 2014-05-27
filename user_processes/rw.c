#include "libc.h"

int main()
{
	char c;
	while (1)
	{
		c = read();
		write(c);
	}
}
