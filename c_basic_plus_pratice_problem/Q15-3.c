#include <stdio.h>


#define SIZE CHAR_BIT * sizeof(int) + 1
int count_on_bit(int num);

int Q15_3(void)
{
	printf("%d",count_on_bit(3));

	return 0;
}


int count_on_bit(int num)
{
	int count = 0;

	while (num > 0)
	{
		count += num % 2;
		num >>= 1;
	}

	return count;
}
