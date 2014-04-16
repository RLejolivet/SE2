

/*
 * basic tools
*/

#include <stdarg.h>
#include "kernel.h"
#include <mini_kernel.h>

void* memcpy(void* dest, const void* src,
			    size_t n)
{
	int i;
	char *d = (char *)dest, *s = (char *)src;

	for (i=0;i<n;i++) d[i] = s[i];

	return dest;
}

int strlen(const char*p)
{
int len=0;
	while (*p++) len += 1;
	return len;
}

char*  strcpy(char* dest, const char* src)
{
char* p=dest;
	while ( (*dest++=*src++)!=0 );
	return p;
}

int   strcmp(const char* s1, const char* s2)
{
	while (*s1 && *s2) {
		if (*s1==*s2) {
			s1++; s2++;
		} else {
			return *s1-*s2;
	}	}
	if ( *s1==0 && *s2==0 ) {
		return 0;
	} else if (*s1==0) {
		return -1;
	} else {
		return 1;
}	}

