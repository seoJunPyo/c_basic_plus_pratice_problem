#include <stdio.h>
#include "util.h"

double get_harmonic_mean(double dlA, double dlB);

int Q9_4(void)
{
	double dlA, dlB;

	printf("�� �� �Է� : ");
	while (scanf_s("%lf %lf", &dlA, &dlB) != 2)
	{
		printf("���� �ƴմϴ�.\n");
		printf("�� �� �Է� : ");
		eat_chars();
	}

	printf("��ȭ ��� : %f", get_harmonic_mean(dlA, dlB));

	return 0;
}

double get_harmonic_mean(double dlA, double dlB)
{
	return 1 / (((1 / dlA) + (1 / dlB)) / 2);
}