#include <stdarg.h>
#include <stdio.h>
#include "libc.h"
//copie la chaine qui est dans le buffer dans le char* passé en paramètre
static void scanf_str(char* s) ;
static void scanf_str(char* s) 
{
	char c = 'a' ;

	while(c != ' ' && c != '\n' && c != '\t')
	{
		c = getchar() ;
		*s++ = c ;
	}
	/* -1 pour remplacer le \n final */
	*(s - 1) = '\0' ;
}

int get_int_from_stdin(int hexa)
{
	char c = getchar() ;
	int res = 0 ;

	while((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
	{
		if(!hexa)
			res = 10 * res + (c - '0') ;
		else if (c >= '0' && c <= '9')
			res = 16 * res + (c - '0') ;
		else
			res = 16 * res + (c - 'a' + 10) ;

		//une version sale avec des ternaires imbriquées juste pour le fun
		//res = (hexa ? 16 : 10) * res + c - (hexa ? 'a' : '0') + ((c >= '0' && c <= '9') ? 0 : (hexa ? 10 : 0) ;
		c = getchar() ;
	}

	return res ;

}

int miniscanf(const char* fmt, ...)
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
							c = getchar() ;
							while(getchar() != '\n') ;
							if(c != '%') //fail
								return -1 ;
							fmt++;
							continue ;
						case 's' :
							scanf_str(va_arg(args, char*)) ;
							fmt++;
							continue ;
						case 'c' :
							*va_arg(args, char*) = getc(stdin) ;
							while(getchar() != '\n') ;
							fmt++;
							continue ;
						case 'x' :
							*va_arg(args, int*) = get_int_from_stdin(1) ;
							fmt++ ;
							continue ;
						case 'd' :
							*va_arg(args, int*) = get_int_from_stdin(0) ;
							fmt++ ;
							continue ;
						default :
							return -2 ; //format invalide
					}
				}
				continue ;
			default :
				c = getc(stdin) ;
				if(c != *fmt)
					return -3 ;
				fmt++ ;
				continue ;
		}
	}
	return 0 ;
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
#if 0
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
#endif
