#ifndef KERNEL_H
#define KERNEL_H

#define DEFAULT_COLORS 0x0d
#define FOCUS__BG_COLOR 0xa0
/**********************************************************************/
/**** sub screen, and print function                               ****/

typedef struct _subscreen 
{
	char* vidmem;
	int col_org, line_org;
	int nblines, nbcols;
	int cline, ccol;
} subscreen;

#include "keyboard.h"

extern subscreen sc_alive, sc_ttyS0, sc_ttyS1, sc_kernel, sc_user;
extern subscreen sc_p1, sc_p2, sc_p3, sc_p4;

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

void do_minikernel_irq0();
void do_minikernel_irq1(int code);

#include "syscalls.h"
void minikernel_syscalls();

#endif
