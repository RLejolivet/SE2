/*
 * basic print to vga screen for debuging
*/

#include <stdarg.h>
#include "kernel.h"
#include <mini_kernel.h>

/*
 * setup has initialiszed the handler and put all
 * information at 0x90000 adressese
*/
#define SCREEN_INFO (*(struct screen_info *)0x90000)


void outb_p (unsigned   char   value, unsigned short port) 
{  
	__asm__ __volatile__ ("out" "b" " %"   "b"   "0,%"  "w"  "1"  "\noutb %%al,$0x80"   : : "a" (value), "Nd" (port));
}

struct screen_info 
{
	unsigned char  orig_x;				/* 0x00 */
	unsigned char  orig_y;				/* 0x01 */
	unsigned short dontuse1;			/* 0x02 -- EXT_MEM_K sits here */
	unsigned short orig_video_page;		/* 0x04 */
	unsigned char  orig_video_mode;		/* 0x06 */
	unsigned char  orig_video_cols;		/* 0x07 */
	unsigned short unused2;				/* 0x08 */
	unsigned short orig_video_ega_bx;	/* 0x0a */
	unsigned short unused3;				/* 0x0c */
	unsigned char  orig_video_lines;	/* 0x0e */
	unsigned char  orig_video_isVGA;	/* 0x0f */
	unsigned short orig_video_points;	/* 0x10 */

	/* VESA graphic mode -- linear frame buffer */
	unsigned short lfb_width;			/* 0x12 */
	unsigned short lfb_height;			/* 0x14 */
	unsigned short lfb_depth;			/* 0x16 */
	unsigned long  lfb_base;			/* 0x18 */
	unsigned long  lfb_size;			/* 0x1c */
	unsigned short dontuse2, dontuse3;	/* 0x20 -- CL_MAGIC and CL_OFFSET here */
	unsigned short lfb_linelength;		/* 0x24 */
	unsigned char  red_size;			/* 0x26 */
	unsigned char  red_pos;				/* 0x27 */
	unsigned char  green_size;			/* 0x28 */
	unsigned char  green_pos;			/* 0x29 */
	unsigned char  blue_size;			/* 0x2a */
	unsigned char  blue_pos;			/* 0x2b */
	unsigned char  rsvd_size;			/* 0x2c */
	unsigned char  rsvd_pos;			/* 0x2d */
	unsigned short vesapm_seg;			/* 0x2e */
	unsigned short vesapm_off;			/* 0x30 */
	unsigned short pages;				/* 0x32 */
						/* 0x34 -- 0x3f reserved for future expansion */
};

/********************************************/
/**** real screan                        ****/
/****    - kernel is alive               ****/
/****    - ttyS0 infos                   ****/
/****    - ttyS1 infos                   ****/
/****    - 4 scroll lines                ****/
/****    - user screen                   ****/
static nblines, nbcols;
static char *vidmem;
static int vidport;

subscreen sc_alive, sc_ttyS0, sc_ttyS1, sc_kernel, sc_user;
subscreen sc_p1, sc_p2, sc_p3, sc_p4 ;


void vga_init()
{
	int nbl;
	int pos ;
	int i;

	if (SCREEN_INFO.orig_video_mode == 7) 
	{
		vidmem = (char *) 0xb0000;
		vidport = 0x3b4;
	} 
	else 
	{
		vidmem = (char *) 0xb8000;
		vidport = 0x3d4;
	}

	nblines = SCREEN_INFO.orig_video_lines;
	nbcols  = SCREEN_INFO.orig_video_cols;

	/* clear screen */
	for (i=0 ; i< (nblines*nbcols*2) ; i += 2) 
	{
		vidmem[i]=' ';
	}

	for(i = 1 ; i < nblines * nbcols*2 ; i += 2)
	{
		/*
		 * 0 : noir
		 * 1 : bleu foncé
		 * 2 : vert
		 * 3 : bleu clair
		 * 4 : rouge
		 * 5 : violet 
		 * 6 : orange
		 * 7 : blanc 
		 * 8 : gris
		 * 9 : bleu 
		 * A : vert clair
		 * B : cyan 
		 * C : rose
		 * D : fuschia
		 * E : jaune
		 * F : blanc
		 */
		vidmem[i] = DEFAULT_COLORS ;
	}

	nbl= nblines;

	/* init alive screen */
	sc_alive.vidmem= vidmem;
	sc_alive.nblines= 2;
	sc_alive.nbcols= nbcols;
	sc_alive.cline=0;
	sc_alive.ccol=0;
	nbl--;

	/* init sc_ttyS0 screen */
	sc_ttyS0.vidmem= sc_alive.vidmem + sc_alive.nblines * nbcols * 2;
	sc_ttyS0.nblines= 1;
	sc_ttyS0.nbcols= nbcols;
	sc_ttyS0.cline=0;
	sc_ttyS0.ccol=0;
	nbl--;

	#if 0
	/* init sc_ttyS1 screen */
	sc_ttyS1.vidmem= sc_ttyS0.vidmem + sc_ttyS0.nblines * nbcols * 2;
	sc_ttyS1.nblines= 1;
	sc_ttyS1.nbcols= nbcols;
	sc_ttyS1.cline=0;
	sc_ttyS1.ccol=0;
	nbl--;

	/* init kernel scroll screen */
	sc_kernel.vidmem= sc_ttyS1.vidmem + sc_ttyS1.nblines * nbcols * 2;
	sc_kernel.nblines= 4;
	sc_kernel.nbcols= nbcols;
	sc_kernel.cline=0;
	sc_kernel.ccol=0;
	nbl -= sc_kernel.nblines;

	/* init user screen */
	sc_user.vidmem=  sc_ttyS0.vidmem + sc_ttyS0.nblines * nbcols * 2;
	sc_user.nblines= 4;
	sc_user.nbcols= nbcols;
	sc_user.cline=0;
	sc_user.ccol=0;
	#endif

	/* init p1 screen */
	sc_p1.vidmem	=	sc_ttyS0.vidmem + sc_ttyS0.nblines * nbcols * 2;
	sc_p1.line_org	=	sc_alive.nblines + sc_ttyS0.nblines ;
	sc_p1.col_org	=	0 ;
	sc_p1.nblines	=	nbl / 2 - 1 ;
	sc_p1.nbcols	=	nbcols / 2 - 1 ;
	sc_p1.cline		=	0 ;
	sc_p1.ccol		=	0 ;

	/* init p2 screen */
	sc_p2.vidmem	=	sc_p1.vidmem ;
	sc_p2.line_org	=	sc_p1.line_org ;
	sc_p2.col_org	=	sc_p1.nbcols + 1 ;
	sc_p2.nblines	=	nbl / 2 - 1;
	sc_p2.nbcols	=	nbcols / 2;
	sc_p2.cline		=	0 ;
	sc_p2.ccol		=	sc_p2.col_org ;

	/* init p3 screen */
	sc_p3.vidmem	=	sc_p1.vidmem + (sc_p1.nblines + 1) * nbcols * 2;
	sc_p3.line_org	=	sc_p1.line_org + sc_p1.nblines + 1 ;
	sc_p3.col_org	=	0 ; 
	sc_p3.nblines 	=	nbl / 2 ;
	sc_p3.nbcols	=	nbcols / 2 - 1 ;
	sc_p3.cline 	=	0 ;
	sc_p3.ccol		=	0 ;

	/* init p4 screen */
	sc_p4.vidmem	=	sc_p3.vidmem ;
	sc_p4.line_org	=	sc_p3.line_org ;
	sc_p4.col_org	=	sc_p3.nbcols + 1 ;
	sc_p4.nblines	=	nbl / 2 ;
	sc_p4.nbcols	=	nbcols / 2 ;
	sc_p4.cline		=	0 ;
	sc_p4.ccol		=	sc_p4.col_org ;
}

static void vkprintf(subscreen* psc, const char* fmt, va_list args);
static void scroll(subscreen *psc);
void border_color(char color, subscreen* sc) ;

void border_color(char color, subscreen* sc)
{
	int i ;
	vgaprintf("%d %d\n", sc->nblines, sc->nbcols) ;

	for(i = 0 ; i < sc->nblines * sc->nbcols ; i++)
	{
		vgaprintf("\ncoucou\n") ;
		kprintc(sc, color) ;
	}

}

void kprintc(subscreen* psc, char c)
{
	int x,y,pos;

	x = psc->ccol;
	y = psc->cline;

	if ( c == '\n' ) 
	{
		x = psc->col_org ;
		if ( ++y >= psc->nblines ) 
		{
			scroll(psc);
			y--;
		}
	} 
	else
	{
		psc->vidmem [ (x + y * nbcols) * 2 ] = c; 
		if ( ++x  - psc->col_org >= psc->nbcols ) 
		{
			x = psc->col_org ;
			if ( ++y >= psc->nblines ) 
			{
				scroll(psc);
				y--;
			}
		}
	}

	psc->ccol  = x;
	psc->cline = y;
#if 1
	//pos = (x + psc->nbcols * y) * 2;	/* Update cursor position */
	pos = -1 ;
	outb_p(14, vidport);
	outb_p(0xff & (pos >> 9), vidport+1);
	outb_p(15, vidport);
	outb_p(0xff & (pos >> 1), vidport+1);
#endif
}

void kprints(subscreen* psc, const char *p)
{
	while (*p)
		kprintc(psc,*p++);
}

void kprintf(subscreen* psc, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vkprintf(psc,fmt,args);
	va_end(args);
}

void vgaprintc(char c)
{ 
	kprintc(&sc_user,c); 
}

void vgaprints(const char* s)
{
	kprints(&sc_user,s);
}

void vgaprintf(const char* fmt,...)
{ 
	va_list args;
	va_start(args, fmt);
	vkprintf(&sc_p1,fmt,args);
	va_end(args);
}

static void scroll(subscreen *psc)
{
	int colonne = 0, ligne = 0 ;

	if (psc->nblines > 1)
	/*
		memcpy ( psc->vidmem,
			 psc->vidmem + psc->nbcols * 2,
			( psc->nblines - 1 ) * psc->nbcols * 2
		);
	*/
	{
		for(ligne = 0 ; ligne < psc->nblines - 1 ; ligne++)
		{
			for(colonne = 0 ; colonne < psc->nbcols ; colonne++)
			{
				psc->vidmem[(ligne * nbcols + psc->col_org + colonne) * 2] = psc->vidmem[((ligne + 1) * nbcols + psc->col_org + colonne) * 2] ;
			}
		}
	}

	for(colonne = 0 ; colonne < psc->nbcols ; colonne++)
	{
		psc->vidmem[((psc->nblines - 1) * nbcols + psc->col_org  + colonne) * 2] = ' ' ;
	}
}

static void vkprintf_str(subscreen* psc, const char* str, int len, char fillwith, int placeleft, int signe)
{
	int i;
	if (len==0) 
	{
		if (signe) kprintc(psc,signe);
		kprints(psc,str);
	} 
	else 
	{
		int slen=strlen(str) + (signe ? 1 : 0);
		if (slen >= len) 
		{
			if (signe) kprintc(psc,signe);
			kprints(psc,str);
		} 
		else if (placeleft) 
		{
			if (signe) kprintc(psc,signe);
			kprints(psc,str);
			for (i=0; i<(len-slen) ; i++) 
			{
				kprintc(psc,fillwith);
			}
		} 
		else 
		{
			if (signe&&(fillwith!=' ')) kprintc(psc,signe);
			for (i=0; i<(len-slen) ; i++)
				kprintc(psc,fillwith);
			if ( signe&&(fillwith==' ')) kprintc(psc,signe);
			kprints(psc,str);
		}	
	}
}

static void vkprintf(subscreen* psc, const char* fmt, va_list args)
{
	int len=0;
	char fillwith=' ';
	int	 placeleft=0;
	int	 signe=0;
	char buf[100];

	while (*fmt) 
	{
		switch (*fmt) 
		{
			case '%' :
				fmt++;
				while (*fmt) 
				{
					switch (*fmt) 
					{
						case '%' : 
							fmt++; kprintc(psc,'%'); 
							goto leave_printarg;
						case 's' : 
							vkprintf_str(psc,va_arg(args, char*), len, fillwith, placeleft,0);
							fmt++;
							goto leave_printarg;
						case 'c' :
							kprintc(psc,va_arg(args, int)&0xff);
							fmt++;
							goto leave_printarg;
						case 'x' :
						case 'X' : 
						{
							char* p=buf;
							unsigned int x= va_arg(args, int);
							int i;
							for (i=0 ; i<7 ; i++, x <<= 4) 
							{
								if ( (x & 0xf0000000) != 0 )
									break;
							}
							for ( ; i<8 ; i++, x <<= 4) 
							{
								char c= (x>>28)&0xf;
								if ( c>=10 )
									*p++= c-10+'a';
								else
									*p++= c+'0';
							}
							*p=0;
							vkprintf_str(psc,buf, len, fillwith, placeleft,0);
							fmt++;
							goto leave_printarg;
						}
						case 'd' :
						case 'i' : 
						{
							char* p=buf;
							int y=1000000000;
							int x= va_arg(args, int);
							if (x<0) 
							{
								signe = '-';
								x = -x;
							} 
							else if (signe)
								signe = '+';
								
							for (    ; y>=10 ; y /= 10) 
							{
								if ( (x/y)>0 )
									break;
							}
							for (    ; y>=10 ; y /= 10) 
							{
								*p++ = (x / y) + '0';
								x = x % y;
							}
							*p++ = x + '0';
							*p=0;
							if (placeleft)
								fillwith=' ';
							vkprintf_str(psc, buf, len, fillwith, placeleft, signe);
							fmt++;
							goto leave_printarg;
						}
						case '0' : 
							fmt++; fillwith='0'; 
							continue;
						case '+' : 
							fmt++; signe= 1; 
							continue;
						case '-' : 
							fmt++; placeleft= 1; 
							continue;
						default:
							if ( (*fmt<'1') || ('9'<=*fmt) ) 
							{
								/* ignore char */
								continue;
							}
							/* get number */
							while (*fmt && !((*fmt<'0') || ('9'<*fmt)) ) 
							{
								len = len*10 + *fmt-'0';
								fmt++;
							}
							continue;
					}	
				}
				leave_printarg:
					len=0;
					fillwith=' ';
					placeleft=0;
					signe=0;
					continue;
			default:
				kprintc(psc,*fmt++);
				continue;
		}
	}	
}

