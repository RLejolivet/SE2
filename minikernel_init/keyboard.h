#ifndef KEYBOARD_H
#define KEYBOARD_H

#define BUFFER_SIZE 1024

typedef enum bool {false, true} bool ;

struct buffer_keyboard 
{
	char* buffer1 ;
	char* buffer2 ;
	char* buffer3 ;
	char* buffer4 ;
	
	bool to_read1 ;
	bool to_read2 ;
	bool to_read3 ;
	bool to_read4 ;
	
	/* tiar stands for There Is A Reader */
	bool tiar1 ;
	bool tiar2 ;
	bool tiar3 ;
	bool tiar4 ;


	char write_to ;
} ;


void print_char(int code) ;
#endif
