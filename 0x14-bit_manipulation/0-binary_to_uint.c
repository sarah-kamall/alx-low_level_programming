#include"main.h"
unsigned int binary_to_uint(const char *b)
{
	int len;
	unsigned int num;
	int j,two;
	int i;

	if (!b)
		return (0);
	num = 0;
	len = strlen(b);
	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		if (b[i] == '0')
			continue;
		j = (len - 1) - i;
		two = 1;
		while (j > 0)
		{
			two *= 2;
			j--;
		}
		num += two;
	}
	return (num);
}
