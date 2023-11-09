#include <stdio.h>
#include "util.h"

double power(double dl, int n);

int Q9_8(void)
{
	double dl;
	int n;

	printf("실수 입력 : ");
	while (scanf_s("%lf", &dl) != 1)
	{
		printf("수가 아닙니다.\n");
		printf("실수 입력 : ");
		eat_chars();
	}

	printf("정수 입력 : ");
	while (scanf_s("%d", &n) != 1)
	{
		printf("수가 아닙니다.\n");
		printf("정수 입력 : ");
		eat_chars();
	}

	printf("%f의 %d승 : %f",dl, n,  power(dl, n));

	return 0;
}

static double power(double dl, int n)
{
	double result = 1;

	if (n > 0)
	{
		for (int i = 0; i < n; i++)
			result *= dl;
	}
	else if (n < 0)
	{
		for (int i = n; i < 0; i++)
			result *= 1 / dl;
	}

	return result;
}