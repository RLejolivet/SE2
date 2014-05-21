#include "libc.h"

typedef enum bool {false, true} bool ;

int main()
{
	int i ;
	miniscanf("%x",&i) ;
	printf("%x\n", i) ;
	printf("%d\n", i) ;

	switch(miniscanf("abcd %d", &i))
	{
		case -1 :
			printf("%% fail\n") ;
			break ;
		case -2 :
			printf("format invalide\n") ;
			break ;
		case -3 :
			printf("caractère inattendu\n") ;
			break ;
		default :
			printf("%d\n", i) ;
	}
	return 0 ;
}

