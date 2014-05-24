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

	/* THIS IS PROCESS 0! */
	// Il manque un LRT ici, je crois - inline assembler for the win
	/* THIS IS PROCESS 0! (omg) */

#ifdef DEBUG_SYSCALLS //test printf
	printf("printf :\n%d %s %x", i, "\ncoucou\n", i) ;

	//test scanf 
	scanf("%d %x %s", &i, &i, lol) ;
#endif

#ifdef DEBUG_VGA
	processes[1].stdout = &sc_p1 ;
	processes[2].stdout = &sc_p2 ;
	processes[3].stdout = &sc_p3 ;
	processes[4].stdout = &sc_p4 ;
#endif
	schedule();
	//while (1) ;
}

