
/* basic types                      */
typedef unsigned int size_t;

/* standard tools                   */
void* memcpy(void* __dest, __const void* __src, size_t __n);
int   strlen(const char*p);
char* strcpy(char* dest, const char*src);
int   strcmp(const char* s1, const char* s2);

/* fonctions to print on vga screen */

void vgainit();
void vgaprintc(char c);			/* print a char */
void vgaprints(const char* s);		/* print a string */
void vgaprintf(const char* fmt,...);	/* basic printf */

/* serials ports */

extern	char	       uart_name[64];
extern	unsigned short ttyS0_base;
extern	unsigned short ttyS1_base;
