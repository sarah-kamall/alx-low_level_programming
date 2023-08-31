#include"main.h"
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int mask,counter;

	mask = n ^ m;
	counter = 0;
	while (mask > 0)
	{
		counter += 1 & mask;
		mask >>= 1;
	}
	return (counter);
}
