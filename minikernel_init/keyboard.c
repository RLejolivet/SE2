#include "kernel.h"

input_buffer in1, in2, in3, in4;

char mappings[88] = 
{ 
	'\0',
	'&',	/* &/1 			: 0x02 - 0x82 */ 
	'e',	/* é/2 			: 0x03 - 0x83 */
	'"',	/* "/3 			: 0x04 - 0x84 */
	'\'',	/* '/4 			: 0x05 - 0x85 */
	'(',	/* (/5 			: 0x06 - 0x86 */
	'-',	/* -/6 			: 0x07 - 0x87 */
	'e',	/* è/7 			: 0x08 - 0x88 */
	'_',	/* _/8 			: 0x09 - 0x89 */
	'c',	/* ç/9 			: 0x0a - 0x8a */
	'a',	/* à/0 			: 0x0b - 0x8b */
	')',	/* )/° 			: 0x0c - 0x8c */
	'=',	/* =/+ 			: 0x0d - 0x8d */
	'\0',
	'\0',
	'a',	/* a 			: 0x10 - 0x90 */
	'z',	/* z 			: 0x11 - 0x91 */
	'e',	/* e 			: 0x12 - 0x92 */
	'r',	/* r 			: 0x13 - 0x93 */
	't',	/* t 			: 0x14 - 0x94 */
	'y',	/* y 			: 0x15 - 0x95 */
	'u',	/* u 			: 0x16 - 0x96 */
	'i',	/* i 			: 0x17 - 0x97 */
	'o',	/* o 			: 0x18 - 0x98 */
	'p',	/* p 			: 0x19 - 0x99 */
	'\0',
	'\0',
	'\n',	/* Enter 		: 0x1c - 0x9c */
	'\0',
	'q',	/* q 			: 0x1e - 0x9e */
	's',	/* s			: 0x1f - 0x9f */
	'd',	/* d			: 0x20 - 0xa0 */
	'f',	/* f			: 0x21 - 0xa1 */
	'g',	/* g			: 0x22 - 0xa2 */
	'h',	/* h			: 0x23 - 0xa3 */
	'j',	/* j			: 0x24 - 0xa4 */
	'k',	/* k			: 0x25 - 0xa5 */
	'l',	/* l			: 0x26 - 0xa6 */
	'm',	/* m 			: 0x27 - 0xa7 */
	'\0',
	'\0',
	'\0',	/* Shift gauche	: 0x2a - 0xaa */
	'\0',
	'w',	/* w 			: 0x2c - 0xac */
	'x',	/* x 			: 0x2d - 0xad */
	'c',	/* c 			: 0x2e - 0xae */
	'v',	/* v 			: 0x2f - 0xaf */
	'b',	/* b 			: 0x30 - 0xb0 */
	'n',	/* n   			: 0x31 - 0xb1 */
	',',	/* ,/?   			: 0x32 - 0xb2 */
	';',	/* ;/.   			: 0x33 - 0xb3 */
	':',	/* ://   			: 0x34 - 0xb4 */
	'!',	/* !/§   			: 0x35 - 0xb5 */
	'\0',	/* Shift droit 	: 0x36 - 0xb6 */
	'*',	/* *(numpad)	: 0x37 - 0xb7 */
	'\0',
	' ',	/* Espace 		: 0x39 - 0xb9 */
	'\0',	/* Caps Lock	: 0x3a - 0xba */
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'7',	/* 7(numpad) 	: 0x47 - 0xc7 */
	'8',	/* 8(numpad) 	: 0x48 - 0xc8 */
	'9',	/* 9(numpad) 	: 0x49 - 0xc9 */
	'-',	/* -(numpad) 	: 0x4a - 0xca */
	'4',	/* 4(numpad) 	: 0x4b - 0xcb */
	'5',	/* 5(numpad) 	: 0x4c - 0xcc */
	'6',	/* 6(numpad) 	: 0x4d - 0xcd */
	'+',	/* +(numpad) 	: 0x4e - 0xce */
	'1',	/* 1(numpad) 	: 0x4f - 0xcf */
	'2',	/* 2(numpad) 	: 0x50 - 0xd0 */
	'3',	/* 3(numpad) 	: 0x51 - 0xd1 */
	'0',	/* 0(numpad) 	: 0x52 - 0xd2 */
	'.'		/* .(numpad) 	: 0x53 - 0xd3 */
} ;


void print_char(int code)
{
	vgaprintf("%c", mappings[code - 1]) ;
}

char uppercase(int code)
{
	char c ;

	switch(code)
	{
		case 0x02 :
		case 0x03 :
		case 0x04 :
		case 0x05 :
		case 0x06 :
		case 0x07 :
		case 0x08 :
		case 0x09 :
		case 0x0a :
			return code-1 + 48 ;
		case 0x0b :
			return '0' ;
		case 0x0d :
			return '+' ;
		case 0x32 :
			return '?' ;
		case 0x33 :
			return '.' ;
		case 0x34 :
			return '/' ;
		default :
			c = mappings[code - 1] ;

			if(c >= 97 && c <= 122)	
				c -= 32 ;
			return c ;
	}
}
