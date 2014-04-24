
#include "kernel.h"
#include <mini_kernel.h>

void ttyS_set_uart_name(char *name)
{
	if (uart_name[0]==0) 
	{
		strcpy(uart_name,name);
	}
	else 
	{
		if (strcmp(uart_name,name)!=0)
			kprintf(&sc_kernel,"ttyS: several UART %s %s\n",
				uart_name,
				name
			);
	}
}

void ttyS_init()
{
	int i,k,irq;
	if ( ttyS_detect(0x3F8) ) 
	{
		ttyS0_base=0x3F8;
		irq=ttyS_getIrq(ttyS0_base);
		irq= (irq&0x8000)!=0 ? (irq>>8)&0x07 : (irq&0x80)!=0 ? (irq&0x07)+8 : -1;
		kprintf(&sc_ttyS0,"SERIAL PORT: UART=%s base=%04x irq=%d",
			uart_name,
			ttyS0_base ,
			irq
		);
	}
	if ( ttyS_detect(0x2F8) ) 
	{
		ttyS1_base=0x2F8;
		irq=ttyS_getIrq(ttyS1_base);
		irq= (irq&0x8000)!=0 ? (irq>>8)&0x07 : (irq&0x80)!=0 ? (irq&0x07)+8 : -1;
		kprintf(&sc_ttyS1,"SERIAL PORT: UART=%s base=%04x irq=%d",
			uart_name,
			ttyS1_base ,
			irq
		);
	}
}
