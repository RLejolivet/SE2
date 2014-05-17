/*
 * entry to minikernel
 * 
 * initialisation are:
 *   - vga driver
 */

#include <mini_kernel.h>
#include "../minikernel_init/kernel.h"

#define DEBUG_VGA


void mini_kernel()
{
	int i;
	int cnt=56;


#ifdef DEBUG_VGA
	vgaprints("enter mini kernel\n");
	//vgaprintf("%d %ss\n",cnt, "coucou");
	//ttyS_config(ttyS0_base,12);	// 9600 bauds */
	kprintf(&sc_p1, "coucou1\n") ;
	kprintf(&sc_p2, "coucou2\n") ;
	kprintf(&sc_p3, "coucou3\n") ;
	kprintf(&sc_p4, "coucou4\n") ;
#endif

	function_test();

//		while (1) ;
}

