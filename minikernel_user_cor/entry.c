/*
 * entry to minikernel
 * 
 * initialisation are:
 *   - vga driver
 */

#include <mini_kernel.h>

void mini_kernel()
{
int nbsend=0,nbrecv=0;
int nberror=0,nberror256=0;
unsigned int exp_c=0;
unsigned int c=0;

	vgaprints("enter mini kernel\n");
	// ttyS_config(ttyS0_base,384);	// 300 bauds 
	// ttyS_config(ttyS0_base,12);	// 9600 bauds 

	/* init irq4 entry 0x24 (timer) */
	{
		extern unsigned long idt_table[];
		extern void minikernel_irq4();
		long addr=(long)minikernel_irq4;
		unsigned short* pidt=(unsigned short*)(idt_table+(0x24<<1));
		pidt[0]= addr;
		pidt[3]= (((long)addr)>>16)&0xffff;
	}

	ttyS_config(ttyS0_base,1);	// 115200 bauds 
	ttyS_config_interrupt(ttyS0_base,1);	// 115200 bauds 

	while (1) {
		int i;
		for (i=0 ; i<10000000 ; i++);
		vgaprintf("send : %02x\n",nbsend);
		ttyS_write(ttyS0_base,nbsend);
		nbsend++;
	} 
#if 0
	while (1) {
		ttyS_write(ttyS0_base,nbsend);
		c=ttyS_read(ttyS0_base);
		if (c!=exp_c) {
			vgaprintf("error: expected %02x, receved %02x\n",exp_c,c);
			nberror++;
			nberror256++;
		}
		exp_c = (c+1)%256;
		nbsend++;
		nbrecv++;
		if ( (nbsend%256)==0 ) {
			vgaprintf("send=%6d recv=%6d nberror=%3d (last 256 nberror=%2d)\n",
				nbsend,nbrecv,nberror,nberror256);
			nberror256=0;
	}	}
	while (1) ;
#endif
}

do_minikernel_irq4(int rbr)
{
static int i=0;
	vgaprintf("recu: %02x\n",rbr);
	// ttyS_config(ttyS0_base,1);	// 115200 bauds 
	// ttyS_config_interrupt(ttyS0_base,1);	// 115200 bauds 
}

