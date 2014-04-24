
#include "ttyS.h"

// #define ttyS0_base "/dev/ttyS1"
#define ttyS0_base "/dev/cua0"

int vt100;

ttyS_config(const char* base,int br)
{
	struct termios att;
	vt100=open(base,O_RDWR);
	if (vt100<0) 
	{
		fprintf(stderr,"can't open %s\n",base);
		exit(1);
	}
	att=satt(vt100,br);
	patt(att);
}

int ttyS_read(char* base)
{
	char c;
	if (read(vt100,&c,1)!=1) {
		fprintf(stderr,"read error\n");
		exit(1);
	}
	return c&0xff;
}

void ttyS_write(char* base, unsigned char x)
{
	char c=x;
	if (write(vt100,&c,1)!=1) {
		fprintf(stderr,"write error\n");
		exit(1);
	}
}

int main()
{
	int nbsend=0,nbrecv=0;
	int nberror=0,nberror256=0;
	unsigned int exp_c=0;
	unsigned int c=0;

	printf("enter mini kernel\n");
	// ttyS_config(ttyS0_base,B300);	// 300 bauds
	// ttyS_config(ttyS0_base,B9600);	// 9600 bauds 
	ttyS_config(ttyS0_base,B115200);	// 115200 bauds 

	while (1) 
	{
		#if 0
			ttyS_write(ttyS0_base,nbsend);
			c=ttyS_read(ttyS0_base);
			if (c!=exp_c) {
				printf("error: expected %02x, receved %02x\n",exp_c,c);
				nberror++;
				nberror256++;
			}
			exp_c = (c+1)&0xff;
			nbsend++;
			nbrecv++;
			if ( (nbsend%256)==0 ) {
				printf("send=%6d recv=%6d nberror=%3d (last 256 nberror=%2d)\n",
					nbsend,nbrecv,nberror,nberror256);
				nberror256=0;
			}
		#else
			char t[100];
			int i;
			static int nb=0;
			printf("--> %02x\n",nb&0xff);
			ttyS_write(ttyS0_base,nb&0xff);
			nb++;
			for (i=0 ; i<100000000 ; i++);
		//	printf("--> 0x%02x\n",ttyS_read(ttyS0_base));
		#endif
	}
}
