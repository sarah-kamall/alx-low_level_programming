#include"main.h"
int get_endianness(void)
{
	unsigned int n;
	unsigned char mask;
	
	n = 1;
	mask = (unsigned char)n;
	if (mask == 1)
		return (1);
	else
		return (0);
}
