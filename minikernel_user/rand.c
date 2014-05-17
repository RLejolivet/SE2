#include <stdio.h>

int seed = 40 ;

void set_seed()
{
	printf("Graine ?\n") ;
	scanf("%d", &seed) ;
}

int rand()
{
	int X = seed ;
	int a = 13, b = 5, m = 1<<5 ;

	seed = (a * X + b) % m ;

	return seed ;
}
