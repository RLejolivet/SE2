#ifndef KERNEL_H
#define KERNEL_H
/**********************************************************************/
/**** sub screen, and print function                               ****/

typedef struct _subscreen 
{
	char* vidmem;
	int nblines, nbcols;
	int cline, ccol;
} subscreen;

extern subscreen sc_alive, sc_ttyS0, sc_ttyS1, sc_kernel, sc_user;

void kprintc(subscreen*, char c);
void kprints(subscreen*, const char* s);
void kprintf(subscreen*, const char* fmt, ...);

/**********************************************************************/
/****  functions for initializing                                  ****/

void vga_init();
void ttyS_init();
void interrupt_init();
void main_init();

/**********************************************************************/
/**** other functions                                              ****/

void ttyS_set_uart_name(char *name);
int  ttyS_detect(unsigned int base);

void minikernel_irq0();
void minikernel_irq1();
void minikernel_syscalls();

void do_minikernel_irq0();
void do_minikernel_irq1(int code);
void do_minikernel_syscalls(int esp, int ebp);

#endif
