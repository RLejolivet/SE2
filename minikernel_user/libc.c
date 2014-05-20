#include <stdarg.h>
static char* 
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
							fmt++;
							c = read() ;
							write(c) ;
							if(c != '%') //fail
								return -1 ;
							continue ;
						case 's' :
						case 'c' :
							c = 
						case 'x' :
						
						case 'd' :
						case 'i' : 
					}
				}
			default :
				fmt++ ;
				continue ;
		}
	}
}
