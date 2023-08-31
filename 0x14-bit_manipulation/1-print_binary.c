#include"main.h"
void print_binary(int x)
{
	unsigned long int mask;
	int f;

	f = 0;
	mask = 1UL<< sizeof(x)*8-1;
	while (mask > 0)
	{
		if (x & mask)
		{
			_putchar('1');
			f = 1;
		}
		else if (f)
			_putchar('0');
		mask>>=1;
	}
	if (!f)
		_putchar('0');
}

