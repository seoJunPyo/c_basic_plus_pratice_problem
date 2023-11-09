#include <stdio.h>
#include "util.h"

void sort(double* dlA, double* dlB, double* dlC);

int Q9_6(void)
{
	double dlA, dlB, dlC;

	printf("�� �� �Է� : ");
	while (scanf_s("%lf %lf %lf", &dlA, &dlB, &dlC) != 3)
	{
		printf("���� �ƴմϴ�.\n");
		printf("�� �� �Է� : ");
		eat_chars();
	}

	sort(&dlA, &dlB, &dlC);
	printf("%f %f %f\n", dlA, dlB, dlC);

	return 0;
}

static void sort(double* dlA, double* dlB, double* dlC)
{
	double dl[3] = { *dlA, *dlB, *dlC };
	double temp;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i - 1; j++)
			if (dl[j] > dl[j + 1])
			{
				temp = dl[j];
				dl[j] = dl[j + 1];
				dl[j + 1] = temp;
			}

	*dlA = dl[0];
	*dlB = dl[1];
	*dlC = dl[2];
}