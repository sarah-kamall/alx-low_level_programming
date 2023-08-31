#include"main.h"
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	mask = 1UL << index;
	if (mask & n)
		return (1);
	else
		return (0);
}
