#include <stdio.h>
#include "util.h"

void large_of(double *dlA, double *dlB);

int Q9_5(void)
{
	double dlA, dlB;

	printf("두 수 입력 : ");
	while (scanf_s("%lf %lf", &dlA, &dlB) != 2)
	{
		printf("수가 아닙니다.\n");
		printf("두 수 입력 : ");
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