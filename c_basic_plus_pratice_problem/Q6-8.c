#include <stdio.h>

int Q6_8(void)
{
	float flA, flB;

	printf("�� �Ǽ� �Է� : ");
	while (scanf_s("%f %f", &flA, &flB) == 2)
	{
		printf("(%f - %f) / (%f x %f) = %f\n", flA, flB, flA, flB, (flA - flB) / (flA * flB));
		printf("�� �Ǽ� �Է� : ");
	}
	
	printf("����!");

	return 0;
}