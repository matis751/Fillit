#include "fillit.h"

int puissance (int *nb, int puissance)
{
	int x;
	x = *nb;
	while (puissance-- >= 2)
		*nb *= x;
	return (*nb);
}

int main()
{
	int a = 2;
	int b = 3;

	puissance(&a, b);
	a = (char)a;
	write (1, 'a', 3);
	write(1, "\n", 1);
	return (1);
}
