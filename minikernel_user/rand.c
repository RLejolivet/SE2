int seed = 40 ;

int rand()
{
	static int X_0 = seed ;
	int a = 10, b = 30, m = 12 ;

	return (a*X_0 + b) % m ;
}
