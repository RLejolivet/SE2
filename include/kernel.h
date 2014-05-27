#ifndef KERNEL_H
#define KERNEL_H

#define COMMUTE_ON

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
void init_borders() ;

/**********************************************************************/
/**** other functions                                              ****/

void ttyS_set_uart_name(char *name);
int  ttyS_detect(unsigned int base);

void minikernel_irq0();
void minikernel_irq1();
void minikernel_exception0() ;
void minikernel_exception1() ;
void minikernel_exception2() ;
void minikernel_exception3() ;
void minikernel_exception4() ;
void minikernel_exception5() ;
void minikernel_exception6() ;
void minikernel_exception7() ;
void minikernel_exception8() ;
void minikernel_exception9() ;
void minikernel_exception10() ;
void minikernel_exception11() ;
void minikernel_exception12() ;
void minikernel_exception13() ;
void minikernel_exception14() ;
void minikernel_exception15() ;
void minikernel_exception16() ;
void minikernel_exception17() ;
void minikernel_exception18() ;
void minikernel_exception19() ;
void minikernel_exception20() ;
void minikernel_exception21() ;
void minikernel_exception22() ;
void minikernel_exception23() ;
void minikernel_exception24() ;
void minikernel_exception25() ;
void minikernel_exception26() ;
void minikernel_exception27() ;
void minikernel_exception28() ;
void minikernel_exception29() ;
void minikernel_exception30() ;
void minikernel_exception31() ;

void do_minikernel_irq0();
void do_minikernel_irq1();
void handle_exception0() ;
void handle_exception1() ;
void handle_exception2() ;
void handle_exception3() ;
void handle_exception4() ;
void handle_exception5() ;
void handle_exception6() ;
void handle_exception7() ;
void handle_exception8() ;
void handle_exception9() ;
void handle_exception10() ;
void handle_exception11() ;
void handle_exception12() ;
void handle_exception13() ;
void handle_exception14() ;
void handle_exception15() ;
void handle_exception16() ;
void handle_exception17() ;
void handle_exception18() ;
void handle_exception19() ;
void handle_exception20() ;
void handle_exception21() ;
void handle_exception22() ;
void handle_exception23() ;
void handle_exception24() ;
void handle_exception25() ;
void handle_exception26() ;
void handle_exception27() ;
void handle_exception28() ;
void handle_exception29() ;
void handle_exception30() ;
void handle_exception31() ;

#include "syscalls.h"
void minikernel_syscalls();


#endif
