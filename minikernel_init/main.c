#include "kernel.h"
#include "keyboard.h"
#include "process.h"
#define CREATE_IDT_ENTRY(number)	addr = (long)minikernel_exception##number ; \
									pidt = (unsigned short*)(idt_table + (number<<1)); \
									pidt[0] = addr ; \
									pidt[3] = (((long)addr)>>16) & 0xffff ;
	
   

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

	/* init exception entries 0x00 - 0x1f */
	{
		long addr ;
		unsigned short* pidt ;
		CREATE_IDT_ENTRY(0) ;
		CREATE_IDT_ENTRY(1) ;
		CREATE_IDT_ENTRY(2) ;
		CREATE_IDT_ENTRY(3) ;
		CREATE_IDT_ENTRY(4) ;
		CREATE_IDT_ENTRY(5) ;
		CREATE_IDT_ENTRY(6) ;
		CREATE_IDT_ENTRY(7) ;
		CREATE_IDT_ENTRY(8) ;
		CREATE_IDT_ENTRY(9) ;
		CREATE_IDT_ENTRY(10) ;
		CREATE_IDT_ENTRY(11) ;
		CREATE_IDT_ENTRY(12) ;
		CREATE_IDT_ENTRY(13) ;
		CREATE_IDT_ENTRY(14) ;
		CREATE_IDT_ENTRY(15) ;
		CREATE_IDT_ENTRY(16) ;
		CREATE_IDT_ENTRY(17) ;
		CREATE_IDT_ENTRY(18) ;
		CREATE_IDT_ENTRY(19) ;
		CREATE_IDT_ENTRY(20) ;
		CREATE_IDT_ENTRY(21) ;
		CREATE_IDT_ENTRY(22) ;
		CREATE_IDT_ENTRY(23) ;
		CREATE_IDT_ENTRY(24) ;
		CREATE_IDT_ENTRY(25) ;
		CREATE_IDT_ENTRY(26) ;
		CREATE_IDT_ENTRY(27) ;
		CREATE_IDT_ENTRY(28) ;
		CREATE_IDT_ENTRY(29) ;
		CREATE_IDT_ENTRY(30) ;
		CREATE_IDT_ENTRY(31) ;
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
	char c ;

	count++;

	if ((count % 20) == 0) 
	{
		unsigned char irq7_0 = inb(0x21);
		unsigned char irq15_8 = inb(0xa1);

		kprintf(&sc_alive,
			"\nmini_kernel is alive since %010d secondes, IRQ [15:0]=%02x%02x\n" 
			"P1:%c   P2:%c   P3:%c   P4:%c    Focus:P%d    CPU:P%d",
			time,irq7_0,irq15_8, processes[1].state, processes[2].state, 
			processes[3].state, processes[4].state, focus_process, current_process
		);


		time++;

	}

#if 0
	/* Debug de ESP et SS, a SUPPRIMER quand ça fonctionne */
	if (current_process == 2)
	{
		short test = 0;
		kprintc(&sc_p4,'A');
		asm volatile("movw %%ss, %0":"=m" (test));
		if(test == 0xb8)kprintc(&sc_p3,'W');
		if(test == 0x90)kprintc(&sc_p3,'Z');
		if(test == 0x18)kprintc(&sc_p3,'X');
		if(test == 0)kprintc(&sc_p3,'V');
		else kprintc(&sc_p3,'Y');

	}
#endif

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
	if((count % 4) == 0 && first_schedule == 1) schedule();

}

void do_minikernel_irq1(int code)
{
	static int count = 0 ;
	static bool caps = false, make_extended = false, break_extended = false ;
	char caractere ;
	task_struct* focused_process = &processes[focus_process];
	subscreen* psc =  focused_process->stdout ;
	int* cursor = &((focused_process->stdin)->pos_ecriture) ;

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
				make_extended = true ;
			break ;
		default :
			if(make_extended)
			{
				make_extended = false ;
				switch(code)
				{
					case UP: 
						if(focus_process > 2)
						{
							border_color(0xff - DEFAULT_COLORS, processes[focus_process].stdout) ;
							focus_process -= 2 ;
							border_color(FOCUS__BG_COLOR, processes[focus_process].stdout) ;
						}
						break ;
					case RIGHT:
						if(focus_process % 2 != 0)
						{
							border_color(0xff - DEFAULT_COLORS, processes[focus_process].stdout) ;
							focus_process++ ;
							border_color(FOCUS__BG_COLOR, processes[focus_process].stdout) ;
						}
						break ;
					case DOWN:
						if(focus_process <= 2)
						{
							border_color(0xff - DEFAULT_COLORS, processes[focus_process].stdout) ;
							focus_process += 2 ;
							border_color(FOCUS__BG_COLOR, processes[focus_process].stdout) ;
						}
						break ;
					case LEFT :
						if(focus_process % 2 == 0)
						{
							border_color(0xff - DEFAULT_COLORS, processes[focus_process].stdout) ;
							focus_process-- ;
							border_color(FOCUS__BG_COLOR, processes[focus_process].stdout) ;
						}
						break ;
				}
			}
			else if (code < 0x81)
			{
				if (focused_process->state == 'I') return;
				caractere = mappings[code - 1] ;
				if(caps)
					caractere = uppercase(code) ;

				if (caractere != '\0')
				{
					focused_process->stdin->buffer_read[*cursor % BUFFER_SIZE] = caractere ;
					(*cursor)++ ;
					if(!focused_process->stdin->unread)
					{
						focused_process->state = 'R' ;
						focused_process->stdin->unread = true ;
					}
					#ifdef DEBUG_SYSCALLS
						in3.unread = true ;
					#endif
int strlen(const char*p)
{
	int len=0;

	while (*p++) 
		len += 1;

	return len;
}
				}
				else if (code == BACKSPACE)
				{
					if(*cursor > 0)	
					{
						(*cursor)-- ;
						focused_process->stdin->buffer_read[*cursor] = ' ' ;
						focused_process->stdin->unread = true ;
					}
				}
			}
			break ;
			
	}

/*	if(code  == 0xe0)
		vgaprintf("extended key pr%d\n", codeessed %03d : %x\n", ++count, code) ;
	else
		vgaprintf("keyboard pressed %010d : %x\n", ++count, code) ;*/
}

void handle_exception0() 
{
	kprintf(processes[current_process].stdout,"exception 0 \n") ;
	kill_process();
}
void handle_exception1() 
{
	kprintf(processes[current_process].stdout,"exception 1 \n") ;
	kill_process();
}
void handle_exception2() 
{
	kprintf(processes[current_process].stdout,"exception 2 \n") ;
	kill_process();
}
void handle_exception3() 
{
	kprintf(processes[current_process].stdout,"exception 3 \n") ;
	kill_process();
}
void handle_exception4() 
{
	kprintf(processes[current_process].stdout,"exception 4 \n") ;
	kill_process();
}
void handle_exception5() 
{
	kprintf(processes[current_process].stdout,"exception 5 \n") ;
	kill_process();
}
void handle_exception6() 
{
	kprintf(processes[current_process].stdout,"exception 6 \n") ;
	kill_process();
}
void handle_exception7() 
{
	kprintf(processes[current_process].stdout,"exception 7 \n") ;
	kill_process();
}
void handle_exception8() 
{
	kprintf(processes[current_process].stdout,"exception 8 \n") ;
	kill_process();
}
void handle_exception9() 
{
	kprintf(processes[current_process].stdout,"exception 9 \n") ;
	kill_process();
}
void handle_exception10() 
{
	kprintf(processes[current_process].stdout,"exception 10 \n") ;
	kill_process();
}
void handle_exception11() 
{
	kprintf(processes[current_process].stdout,"exception 11 \n") ;
	kill_process();
}
void handle_exception12() 
{
	kprintf(processes[current_process].stdout,"exception 12 \n") ;
	kill_process();
}
void handle_exception13() 
{
	kprintf(processes[current_process].stdout,"exception 13 \n") ;
	kill_process();
}
void handle_exception14() 
{
	kprintf(processes[current_process].stdout,"exception 14 \n") ;
	kill_process();
}
void handle_exception15() 
{
	kprintf(processes[current_process].stdout,"exception 15 \n") ;
	kill_process();
}
void handle_exception16() 
{
	kprintf(processes[current_process].stdout,"exception 16 \n") ;
	kill_process();
}
void handle_exception17() 
{
	kprintf(processes[current_process].stdout,"exception 17 \n") ;
	kill_process();
}
void handle_exception18() 
{
	kprintf(processes[current_process].stdout,"exception 18 \n") ;
	kill_process();
}
void handle_exception19() 
{
	kprintf(processes[current_process].stdout,"exception 19 \n") ;
	kill_process();
}
void handle_exception20() 
{
	kprintf(processes[current_process].stdout,"exception 20 \n") ;
	kill_process();
}
void handle_exception21() 
{
	kprintf(processes[current_process].stdout,"exception 21 \n") ;
	kill_process();
}
void handle_exception22() 
{
	kprintf(processes[current_process].stdout,"exception 22 \n") ;
	kill_process();
}
void handle_exception23() 
{
	kprintf(processes[current_process].stdout,"exception 23 \n") ;
	kill_process();
}
void handle_exception24() 
{
	kprintf(processes[current_process].stdout,"exception 24 \n") ;
	kill_process();
}
void handle_exception25() 
{
	kprintf(processes[current_process].stdout,"exception 25 \n") ;
	kill_process();
}
void handle_exception26() 
{
	kprintf(processes[current_process].stdout,"exception 26 \n") ;
	kill_process();
}
void handle_exception27() 
{
	kprintf(processes[current_process].stdout,"exception 27 \n") ;
	kill_process();
}
void handle_exception28() 
{
	kprintf(processes[current_process].stdout,"exception 28 \n") ;
	kill_process();
}
void handle_exception29() 
{
	kprintf(processes[current_process].stdout,"exception 29 \n") ;
	kill_process();
}
void handle_exception30() 
{
	kprintf(processes[current_process].stdout,"exception 30 \n") ;
	kill_process();
}
void handle_exception31() 
{
	kprintf(processes[current_process].stdout,"exception 31 \n") ;
	kill_process();
}
