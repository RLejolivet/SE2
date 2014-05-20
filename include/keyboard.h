#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "process.h"

#define BUFFER_SIZE 1024

#define LEFT_SHIFT_MC 0x2a
#define LEFT_SHIFT_BC 0xaa
#define RIGHT_SHIFT_MC 0x36
#define RIGHT_SHIFT_BC 0xb6
#define CAPS_LOCK_MC 0x3a
#define CAPS_LOCK_BC 0xba
#define	UP		0x48
#define DOWN	0x50
#define LEFT	0x4b
#define	RIGHT	0X4d

typedef enum bool {false, true} bool ;

struct stdin 
{
	char* buffer_read[BUFFER_SIZE] ;
	int pos_lecture ;
	int pos_ecriture ;
} ;

extern char mappings[] ;

void print_char(int code) ;
char uppercase(int c) ;
#endif
