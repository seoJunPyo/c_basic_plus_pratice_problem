#include <stdio.h>
#include "util.h"

double get_harmonic_mean(double dlA, double dlB);

int Q9_4(void)
{
	double dlA, dlB;

	printf("두 수 입력 : ");
	while (scanf_s("%lf %lf", &dlA, &dlB) != 2)
	{
		printf("수가 아닙니다.\n");
		printf("두 수 입력 : ");
		eat_chars();
	}

	printf("조화 평균 : %f", get_harmonic_mean(dlA, dlB));

	return 0;
}

double get_harmonic_mean(double dlA, double dlB)
{
	return 1 / (((1 / dlA) + (1 / dlB)) / 2);
}