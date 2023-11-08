#include <stdio.h>

int Q6_8(void)
{
	float flA, flB;

	printf("두 실수 입력 : ");
	while (scanf_s("%f %f", &flA, &flB) == 2)
	{
		printf("(%f - %f) / (%f x %f) = %f\n", flA, flB, flA, flB, (flA - flB) / (flA * flB));
		printf("두 실수 입력 : ");
	}
	
	printf("종료!");

	return 0;
}