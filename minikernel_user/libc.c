#include <stdarg.h>

//copie la chaine qui est dans le buffer dans le char* passé en paramètre
static void scanf_str(va_arg(args, char*)) ;
int scanf(char* fmt, ...)
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
							*va_arg = read() ;
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
