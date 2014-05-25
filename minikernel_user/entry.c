/*
 * entry to minikernel
 * 
 * initialisation are:
 *   - vga driver
 */

#include <mini_kernel.h>
#include "kernel.h"
#include "../user_includes/libc.h"

//#define DEBUG_VGA

void init_borders()
{
	int  p = 0 ;

	for (p = 1 ; p < 5 ; p++)
	{
		border_color(0xff - DEFAULT_COLORS, processes[p].stdout) ;
	}
	border_color(FOCUS__BG_COLOR, processes[1].stdout) ;
}


void mini_kernel()
{
	int i;
	int cnt=56;
	unsigned short tss0;

	init_borders() ;


#ifdef DEBUG_VGA
	vgaprints("enter mini kernel\n");
	//vgaprintf("%d %ss\n",cnt, "coucou");
	//ttyS_config(ttyS0_base,12);	// 9600 bauds */
	kprintf(&sc_p1, "coucou1\n") ;
	kprintf(&sc_p2, "coucou2\n") ;
	kprintf(&sc_p3, "coucou3\n") ;
	kprintf(&sc_p4, "coucou4\n") ;
#endif

#ifdef DEBUG_SYSCALLS
	// Cette fonction de test ne devrait pas être appellée si les commutations fonctionnent
	//function_test();
#endif

#ifdef DEBUG_SYSCALLS //test printf
	printf("printf :\n%d %s %x", i, "\ncoucou\n", i) ;

	//test scanf 
	scanf("%d %x %s", &i, &i, lol) ;
#endif

	/* THIS IS PROCESS 0! */
	// Il manque un LTR ici, je crois - inline assembler for the win
#ifdef COMMUTE_ON
	tss0 = 0x20;
	__asm__ __volatile__(
			"ltr %0"
			:
			: "r" (tss0)
			);
#endif
	schedule();
	//while (1) ;
}

