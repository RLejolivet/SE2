/*
 * entry to minikernel
 * 
 * initialisation are:
 *   - vga driver
 */

#include <mini_kernel.h>

void mini_kernel()
{
int i;
int cnt=56;

	vgaprints("enter mini kernel\n");
	vgaprintf("%d %ss\n",cnt, "coucou");
	ttyS_config(ttyS0_base,12);	// 9600 bauds */

	while (1) ;
}

