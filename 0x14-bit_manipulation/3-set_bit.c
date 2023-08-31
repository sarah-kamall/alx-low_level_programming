#include"main.h"
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;
	if (n + index)
	{
	mask = 1UL << index;

	*n = *n | mask;
	return (1);
	}
	else
		return (-1);
}
