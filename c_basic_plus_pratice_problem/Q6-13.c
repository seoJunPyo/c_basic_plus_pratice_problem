#include <stdio.h>
#define SIZE 8
int two_pow(int n);

int Q6_13(void)
{
	int nums[SIZE], idx = 0;
	
	for (int i = 0; i < SIZE; i++)
		nums[i] = two_pow(i + 1);

	do
		printf("%d ", nums[idx++]);
	while (idx < SIZE);

	return 0;
}

int two_pow(int n)
{
	if (n == 0) return 1;
	return 2 * two_pow(n - 1);
}