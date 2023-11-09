#include <stdio.h>
#include "util.h"

double min(double x, double y);

int Q9_1(void)
{
	double x, y;
	printf("비교할 두 수 입력 : ");
	while (scanf_s("%lf %lf", &x, &y) != 2)
	{
		printf("수를 입력하세요.\n");
		eat_chars();
	}

	printf("%f와 %f 중 작은 것은 %f", x, y, min(x, y));

	return 0;
}

static double min(double x, double y)
{
	return x > y ? y : x;
}