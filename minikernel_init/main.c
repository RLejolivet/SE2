#include "kernel.h"
#include "keyboard.h"
#include "process.h"
#define SCREEN_INFO (*(struct screen_info *)0x90000)
#define	UP		0x48
#define DOWN	0x50
#define LEFT	0x4b
#define	RIGHT	0X4d

unsigned char  inb  (unsigned short port) 
{ 
	unsigned char  _v;
	__asm__ __volatile__ ("in" "b" " %"  "w"  "1,%"   ""   "0"  : "=a" (_v) : "Nd" (port)   ); 
	return _v;
}

/*
unsigned char  inb_p (unsigned short port) 
{ 
	unsigned char  _v;  
	__asm__ __volatile__ ("in" "b" " %"  "w"  "1,%"   ""   "0"  "\noutb %%al,$0x80"   : "=a" (_v) : "Nd" (port)   ); 
	return _v; 
}
*/

unsigned short  inw  (unsigned short port) 
{ 
	unsigned short  _v;  
	__asm__ __volatile__ ("in" "w" " %"  "w"  "1,%"   ""   "0"  : "=a" (_v) : "Nd" (port)   ); 
	return _v; 
}

/*
unsigned short  inw_p (unsigned short port) 
{ 
	unsigned short  _v;  
	__asm__ __volatile__ ("in" "w" " %"  "w"  "1,%"   ""   "0"  "\noutb %%al,$0x80"   : "=a" (_v) : "Nd" (port)   ); 
	return _v; 
}

*/
void outb  (unsigned   char   value, unsigned short port) 
{ 
	__asm__ __volatile__ ("out" "b" " %"   "b"   "0,%"  "w"  "1"  : : "a" (value), "Nd" (port)); 
}

/*
void outb_p (unsigned   char   value, unsigned short port) 
{  
	__asm__ __volatile__ ("out" "b" " %"   "b"   "0,%"  "w"  "1"  "\noutb %%al,$0x80"   : : "a" (value), "Nd" (port));
}
*/

void outw  (unsigned   short   value, unsigned short port) 
{  
	__asm__ __volatile__ ("out" "w" " %"   "w"   "0,%"  "w"  "1"  : : "a" (value), "Nd" (port)); 
}

/*
void outw_p (unsigned   short   value, unsigned short port) 
{  
	__asm__ __volatile__ ("out" "w" " %"   "w"   "0,%"  "w"  "1"  "\noutb %%al,$0x80"   : : "a" (value), "Nd" (port));
}
*/

char saved_char ;
void main_init()
{
	char rtc_A, rtc_B, rtc_C;
	int i;
	extern unsigned long idt_table[];


	/* init irq0 entry 0x20 (timer) */
	{
		long addr = (long)minikernel_irq0;
		unsigned short* pidt = (unsigned short*)(idt_table + (0x20<<1));

		pidt[0] = addr; /* première moitié de l'offset */
		/* on laisse tranquille 32 bits du descripteur */
		pidt[3] = (((long)addr)>>16) & 0xffff; /* 2e moitié de l'offset */
	}

	/* init irq1 entry 0x21 (keyboard) */
	{	
		long addr = (long)minikernel_irq1;
		unsigned short* pidt = (unsigned short*)(idt_table + (0x21<<1));
		pidt[0] = addr ;
		pidt[3] = (((long)addr)>>16) & 0xffff; 
	}

	/* init syscalls entry 0x80 (syscalls) */
	{	
		long addr = (long)minikernel_syscalls;
		unsigned short* pidt = (unsigned short*)(idt_table + (0x80<<1));
		pidt[0] = addr ;
		pidt[3] = (((long)addr)>>16) & 0xffff; 
	}

	/* init processes */
	init_processes();
}

void do_minikernel_irq0()
{
	static int count=-1;
	static int time=0;
	static bool blink = false ;
	char c ;

	count++;

	if ((count % 20) == 0) 
	{
		unsigned char irq7_0 = inb(0x21);
		unsigned char irq15_8 = inb(0xa1);

		kprintf(&sc_alive,
			"\nmini_kernel is alive since %010d secondes, IRQ [15:0]=%02x%02x\n" 
			"P1:%c   P2:%c   P3:%c   P4:%c    Focus:P%d",
			time,irq7_0,irq15_8, processes[1].state, processes[2].state, 
			processes[3].state, processes[4].state, focus_process
		);


		time++;

	}

	// On décrémente les compteurs d'attente, et libère les processes qui ne sont plus bloqués
	for(c=1; c<=4; c++)
	{
		if(processes[c].count > 0) 
		{
			processes[c].count--;
			if(processes[c].count == 0 && processes[c].state == 'A') 
				processes[c].state = 'R';
		}
	}

	/* On schedule tous les 5 coups d'horloge */
	if((count % 5) == 0) schedule();
}

void do_minikernel_irq1(int code)
{
	static int count = 0 ;
	static bool caps = false, make_extended = false, break_extended = false ;
	char caractere ;
	subscreen* psc =  processes[focus_process].stdout ;

	switch(code)
	{
		case LEFT_SHIFT_MC :
		case LEFT_SHIFT_BC :
		case RIGHT_SHIFT_MC :
		case RIGHT_SHIFT_BC :
		case CAPS_LOCK_MC :
			caps = !caps ;
			break ;
		case 0xe0:
			if(!make_extended)
			{
				make_extended = true ;
				break_extended = false ;
			}
			else
			{
				make_extended = false ;
				break_extended = true ;
			}
			break ;
		default :
			if(make_extended)
			{
				make_extended = false ;
				switch(code)
				{
					case UP: 
						if(focus_process > 2)
							focus_process -= 2 ;
						break ;
					case RIGHT:
						if(focus_process % 2 != 0)
							focus_process++ ;
						break ;
					case DOWN:
						if(focus_process <= 2)
							focus_process += 2 ;
						break ;
					case LEFT :
						if(focus_process % 2 == 0)
							focus_process-- ;
						break ;
				}
			}
			else if (code < 0x81)
			{
				caractere = mappings[code - 1] ;
				if(caps)
					caractere = uppercase(code) ;

				if (caractere != '\0')
					kprintc(psc, caractere) ;
				else if (code == 0x0e)
				{
					if(psc->ccol > 0)	
					{
						psc->ccol-- ;
						kprintc(psc, ' ') ;
						psc->ccol-- ;
					}
				}
			}
			break ;
			
	}

/*	if(code  == 0xe0)
		vgaprintf("extended key pressed %03d : %x\n", ++count, code) ;
	else
		vgaprintf("keyboard pressed %010d : %x\n", ++count, code) ;*/
}

