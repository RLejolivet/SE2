#include <stdarg.h>
#include "mini_kernel.h"
#include "../user_includes/libc.h"

// ben strlen quoi
int strlen(const char*p)
{
	int len=0;

	while (*p++) 
		len += 1;

	return len;
}

//copie la chaine qui est dans le buffer dans le char* passé en paramètre
static void scanf_str(char* s) ;
static void scanf_str(char* s) 
{
	char c = 'a' ;

	while(c != ' ' && c != '\n' && c != '\t')
	{
		c = read() ;
		*s++ = c ;
	}
	/* -1 pour remplacer le \n final */
	*(s - 1) = '\0' ;
}

static int get_int_from_stdin(int hexa)
{
	char c = read() ;
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
		c = read() ;
	}

	return res ;

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
							while(read() != '\n') ;
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
							while(read() != '\n') ;
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
				c = read() ;
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

static void writes(const char* s)
{
	while(*s)
		write(*s++) ;
}

static void printf_str(const char* str, int len, char fillwith, int placeleft, int signe)
{
	int i;
	/* Ceci est du code copié collé so....what the HELL IS 'len' ???? */
	if (len==0) 
	{
		if (signe) 
			write(signe);
		writes(str);
	} 
	else 
	{
		int slen=strlen(str) + (signe ? 1 : 0);
		if (slen >= len) 
		{
			if (signe) 
				write(signe);
			writes(str);
		} 
		else if (placeleft) 
		{
			if (signe) 
				write(signe);
			writes(str);
			for (i=0; i<(len-slen) ; i++) 
			{
				write(fillwith);
			}
		} 
		else 
		{
			if (signe && (fillwith != ' ')) 
				write(signe);

			for (i = 0 ; i < (len-slen) ; i++)
				write(fillwith);

			if (signe && (fillwith==' ')) 
				write(signe);

			writes(str);
		}	
	}
}

int printf(const char* fmt, ...)
{
	int len=0;
	char fillwith=' ';
	int	 placeleft=0;
	int	 signe=0;
	char buf[100];
	va_list args ;
	
	va_start(args, fmt) ;

	while (*fmt) 
	{
		switch (*fmt) 
		{
			case '%' :
				fmt++;
				while (*fmt) 
				{
					switch (*fmt) 
					{
						case '%' : 
							fmt++; 
							write('%'); 
							goto leave_printarg;
						case 's' : 
							printf_str(va_arg(args, char*), len, fillwith, placeleft,0);
							fmt++;
							goto leave_printarg;
						case 'c' :
							write(va_arg(args, int) & 0xff);
							fmt++;
							goto leave_printarg;
						case 'x' :
						case 'X' : 
						{
							char* p = buf ;
							unsigned int x = va_arg(args, int) ;
							int i ;
							for (i = 0 ; i < 7 ; i++, x <<= 4) 
							{
								if ( (x & 0xf0000000) != 0 )
									break ;
							}
							for ( ; i < 8 ; i++, x <<= 4) 
							{
								char c = (x>>28) & 0xf ;
								if ( c >= 10 )
									*p++ = c-10 + 'a';
								else
									*p++ = c + '0';
							}
							*p = 0 ;
							printf_str(buf, len, fillwith, placeleft,0);
							fmt++ ;
							goto leave_printarg;
						}
						case 'd' :
						case 'i' : 
						{
							char nb[12] ;
							int x = va_arg(args, int) ;


							
						/*
							char* p = buf;
							int y = 1000000000;

							if (x < 0) 
							{
								signe = '-' ;
								x = -x ;
							} 
							else if (signe)
								signe = '+';
								
							for ( ; y>=10 ; y /= 10) 
							{
								if ( (x/y) >0 )
									break ;
							}
							for ( ; y>=10 ; y /= 10) 
							{
								*p++ = (x / y) + '0';
								x = x % y;
							}
							*p++ = x + '0';
							*p=0;
							if (placeleft)
								fillwith=' ';
							printf_str(buf, len, fillwith, placeleft, signe);
							fmt++;
							*/
							goto leave_printarg;
						}
						case '0' : 
							fmt++; 
							fillwith='0'; 
							continue;
						case '+' : 
							fmt++; 
							signe= 1; 
							continue;
						case '-' : 
							fmt++; 
							placeleft= 1; 
							continue;
						default:
							if ( (*fmt<'1') || ('9'<=*fmt) ) 
							{
								/* ignore char */
								continue;
							}
							/* get number */
							while (*fmt && !((*fmt<'0') || ('9'<*fmt)) ) 
							{
								len = len*10 + *fmt-'0';
								fmt++;
							}
							continue;
					}	
				}
				leave_printarg:
					len = 0;
					fillwith = ' ';
					placeleft = 0;
					signe = 0;
					continue;
			default:
				write(*fmt++) ;
				continue ;
		}
	}	
	return 0 ;
}
