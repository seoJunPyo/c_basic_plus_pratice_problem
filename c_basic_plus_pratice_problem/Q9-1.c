#include <stdio.h>
#include "util.h"

double min(double x, double y);

int Q9_1(void)
{
	double x, y;
	printf("���� �� �� �Է� : ");
	while (scanf_s("%lf %lf", &x, &y) != 2)
	{
		printf("���� �Է��ϼ���.\n");
		eat_chars();
	}

	printf("%f�� %f �� ���� ���� %f", x, y, min(x, y));

	return 0;
}

static double min(double x, double y)
{
	return x > y ? y : x;
}