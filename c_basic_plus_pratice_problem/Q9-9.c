#include <stdio.h>
#include "util.h"

double power(double dl, int n);

int Q9_9(void)
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

	printf("%f�� %d�� : %f", dl, n, power(dl, n));

	return 0;
}

static double power(double dl, int n)
{
	if (n > 0)
		return dl * power(dl, n - 1);

	if (n < 0)
		return 1 / dl * power(dl, n + 1);

	return 1;
}