#include <stdio.h>
#include "util.h"

double power(double dl, int n);

int Q9_8(void)
{
	double dl;
	int n;

	printf("�Ǽ� �Է� : ");
	while (scanf_s("%lf", &dl) != 1)
	{
		printf("���� �ƴմϴ�.\n");
		printf("�Ǽ� �Է� : ");
		eat_chars();
	}

	printf("���� �Է� : ");
	while (scanf_s("%d", &n) != 1)
	{
		printf("���� �ƴմϴ�.\n");
		printf("���� �Է� : ");
		eat_chars();
	}

	printf("%f�� %d�� : %f",dl, n,  power(dl, n));

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