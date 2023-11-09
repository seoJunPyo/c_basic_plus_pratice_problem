#include <stdio.h>
#include "util.h"

void large_of(double *dlA, double *dlB);

int Q9_5(void)
{
	double dlA, dlB;

	printf("�� �� �Է� : ");
	while (scanf_s("%lf %lf", &dlA, &dlB) != 2)
	{
		printf("���� �ƴմϴ�.\n");
		printf("�� �� �Է� : ");
		eat_chars();
	}

	large_of(&dlA, &dlB);

	return 0;
}

void large_of(double *dlA, double *dlB)
{
	double max = *dlA > *dlB ? *dlA : *dlB;

	*dlA = max;
	*dlB = max;
}