#include <stdarg.h>
#include "../user_includes/libc.h"

//copie la chaine qui est dans le buffer dans le char* passé en paramètre
static void scanf_str(char* s) ;
static void scanf_str(char* s) 
{
	
}

int scanf(const char* fmt, ...)
{
	va_list args ;
	va_start(args, fmt) ;
	char buff[BUFFER_SIZE] ;
	char c ;
	int i = 0 ;

	while(*fmt)
	{
		switch(*fmt)
		{
			case '%' :
				fmt++ ;
				while(*fmt)
				{
					switch(*fmt)
					{
						case '%' :
							c = read() ;
							write(c) ;
							if(c != '%') //fail
								return -1 ;
							fmt++;
							continue ;
						case 's' :
							scanf_str(va_arg(args, char*)) ;
							fmt++;
							continue ;
						case 'c' :
							*va_arg(args, char*) = read() ;
							fmt++;
							continue ;
						case 'x' :
						case 'd' :
						case 'i' : 
							write('f');write('u');write('c');write('k');write(' ');write('t');write('h');write('i');write('s');write(' ');write('s');write('h');write('i');write('t');write('\n');
					}
				}
			default :
				c = read() ;
				if(c != *fmt)
					return -2 ;
				fmt++ ;
				continue ;
		}
	}
}

void sleep(int time)
{

	__asm__ __volatile__(
			"movl $0x0, %%eax\n\t"
			"movl %0, %%ebx\n\t"
			"int $0x80"		/* Appel système */
			: 
			: "m" (time)		/* Passe time comme argument dans ebx */
			: "%eax", "%ebx"
			);
}

char read()
{
	int res;

	__asm__ __volatile__(
			"movl $0x2, %%eax\n\t"
			"int $0x80\n\t"		/* Appel système */
			"movl %%eax, %0"
			: "=m" (res)		/* Met le résultat de l'appel (eax) dans res */
			: 
			: "eax");

	return res;

}

void write(char input)
{
	int extended_input = input;
	
	__asm__ __volatile__(
			"movl $0x1, %%eax\n\t"
			"movl %0, %%ebx\n\t"
			"int $0x80"		/* Appel système */
			: 
			: "m" (extended_input)	/* Passe extended_input comme argument dans ebx */
			: "eax", "ebx"
			);
}
