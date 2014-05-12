#include "kernel.h"
#include "keyboard.h"
#include "process.h"
#define SCREEN_INFO (*(struct screen_info *)0x90000)

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
			"\nmini_kernel is alive since %010d secondes, IRQ [15:0]=%02x%02x\nP1:%c P2:%c P3:%c P4:%c",
			time,irq7_0,irq15_8, process_1.state, process_2.state, 
			process_3.state, process_4.state
		);


		time++;

	}
}

void do_minikernel_irq1(int code)
{
	static int count = 0 ;
	static bool caps = false, make_extended = false, break_extended = false ;
	char caractere ;
	subscreen* psc = &sc_p2 ;

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
				switch(code)
				{
					case 0x48: //haut
						if(psc->cline > 0)
							psc->cline-- ;
						break ;
					case 0x4d: //droite
						if(psc->ccol < 16 * 12)
							psc->ccol++ ;
						break ;
					case 0x50: //bas
						if(psc->cline < 9 * 12)
							psc->cline++ ;
						break ;
					case 0x4b: //gauche
						if(psc->ccol > 0)
							psc->ccol-- ;
						break ;
				}
			}
			else if (code < 0x81)
			{
				caractere = mappings[code - 1] ;
				if(caps)
					caractere = uppercase(code) ;

				if (caractere != '\0')
					kprintf(psc, "%c", caractere) ;
				else if (code == 0x0e)
				{
					if(psc->ccol > 0)	
					{
						psc->ccol-- ;
						vgaprintf(" ") ;
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

void do_minikernel_syscalls(int esp, int ebp)
{
	vgaprintf("esp : %x\nebp : %x\n", esp, ebp);
}
