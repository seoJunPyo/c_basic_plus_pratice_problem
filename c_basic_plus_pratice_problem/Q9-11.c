#include <stdio.h>

static fibonacci(int n);

int Q9_11(void)
{
	fibonacci(10);

	return 0;
}

static fibonacci(int n)
{
	int prev = 0, cur = 1, temp;

	for (int i = 0; i < n; i++)
	{
		printf("%d ", cur);

		temp = cur;
		cur = prev + cur;
		prev = temp;
	}

}