#include <stdio.h>

int Q3_8(void)
{
	double cup;
	const double CUP_TO_PINT = 0.5;
	const double CUP_TO_OUNCES = 8;
	const double CUP_TO_TABLESPOONS = CUP_TO_OUNCES * 2;
	const double COP_TO_TEASPOONS = CUP_TO_TABLESPOONS * 3;

	printf("부피 입력 (cup) : ");
	scanf_s("%lf", &cup);

	printf("pint : %f\n", cup * CUP_TO_PINT);
	printf("ounces : %f\n", cup * CUP_TO_OUNCES);
	printf("tablespoons : %f\n", cup * CUP_TO_TABLESPOONS);
	printf("teaspoons : %f\n", cup * COP_TO_TEASPOONS);

	return 0;
}