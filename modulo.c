#include <stdio.h>

int main(int x, char **av)
{
	int c;

	c = (*av[1] + *av[2]) % (*av[3] + *av[4]);
	printf("modulo = %d\n", c);
	
	return (1);
}
