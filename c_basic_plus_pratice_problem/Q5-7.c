#include <stdio.h>
#include "util.h"

float cube(float fl);

int Q5_7(void)
{
	float fl;

	printf("실수 입력 : ");
	while (scanf_s("%f", &fl) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
	}

	printf("%f의 세제곱은 %f입니다.\n", fl, cube(fl));

	return 0;
}

float cube(float fl)
{
	return fl * fl * fl;
}