#include <stdio.h>

float calc_Q6_9(float flA, float flB);

int Q6_9(void)
{
	float flA, flB;

	printf("�� �Ǽ� �Է� : ");
	while (scanf_s("%f %f", &flA, &flB) == 2)
	{
		printf("(%f - %f) / (%f x %f) = %f\n", flA, flB, flA, flB, calc_Q6_9(flA, flB));
		printf("�� �Ǽ� �Է� : ");
	}

	printf("����!");

	return 0;
}

float calc_Q6_9(float flA, float flB)
{
	return (flA - flB) / (flA * flB);
}