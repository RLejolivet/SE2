#include "libc.h"

int seed = 40 ;

void set_seed()
{
	char format1[10] = "Graine ?\n", format2[3] = "%d";
	printf(format1) ;
	scanf(format2, &seed) ;
}

int rand()
{
	int X = seed ;
	int a = 13, b = 5, m = 1<<5 ;

	seed = (a * X + b) % m ;

	return seed ;
}
