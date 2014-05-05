#include "kernel.h"

char mappings[88] = { 
	'\0',	/* Escape */
	'1',	/* 1 */ 
	'2',	/* 2 */
	'3',	/* 3 */
	'4',	/* 4 */
	'5',	/* 5 */
	'6',	/* 6 */
	'7',	/* 7 */
	'8',	/* 8 */
	'9',	/* 9 */
	'0',	/* 0 */
	')',	/* ) */
	'=',	/* = */
	'\0',	/* Backspace */
	'\t',	/* Tabulation */	
	'a',	/* a */
	'z',	/* z */
	'e',	/* e */
	'r',	/* r */
	't',	/* t */
	'y',	/* y */
	'u',	/* u */
	'i',	/* i */
	'o',	/* o */
	'p',	/* p */
	'^',	/* ^ */
	'$',	/* $ */
	'\n',	/* Enter */
	'\0',	/* Ctrl */
	'q',	/* q */
	's',	/* s */
	'd',	/* d */
	'f',	/* f */
	'g',	/* g */
	'h',	/* h */
	'j',	/* j */
	'k',	/* k */
	'l',	/* l */
	'm',	/* m */
	'\0',	/* ù */
	'\0',	/* ² */
	'\0',	/* Shift gauche */
	'*',	/* * */
	'w',	/* w */
	'x',	/* x */
	'c',	/* c */
	'v',	/* v */
	'b',	/* b */
	'n',	/* n */
	',',	/* , */
	';',	/* ; */
	':',	/* : */
	'!',	/* ! */
	'\0',	/* Shift droit */
	'*',	/* *(numpad) */
	'\0',	/* Alt */
	' ',	/* Espace */
	'\0',	/* Caps Lock */
	'\0',	/* F1 */
	'\0',	/* F2 */
	'\0',	/* F3 */
	'\0',	/* F4 */
	'\0',	/* F5 */
	'\0',	/* F6 */
	'\0',	/* F7 */
	'\0',	/* F8 */
	'\0',	/* F9 */
	'\0',	/* F10 */
	'\0',	/* Verr num */
	'\0',	/* Arrêt défil. */
	'7',	/* 7(numpad) */
	'8',	/* 8(numpad) */
	'9',	/* 9(numpad) */
	'-',	/* -(numpad) */
	'4',	/* 4(numpad) */
	'5',	/* 5(numpad) */
	'6',	/* 6(numpad) */
	'+',	/* +(numpad) */
	'1',	/* 1(numpad) */
	'2',	/* 2(numpad) */
	'3',	/* 3(numpad) */
	'0',	/* 0(numpad) */
	'.',	/* .(numpad) */
	'>',	/* > */
	'\0',	/* F11 */
	'\0'	/* F12 */
} ;

void print_char(int code)
{
	/*
	 * Pour ignorer les break codes
	 */
	static unsigned short aldosterone = 1 ;

	if (aldosterone++ % 2 != 0)
		vgaprintf("%c", mappings[code - 1]) ;
}
