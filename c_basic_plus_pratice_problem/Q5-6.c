#include <stdio.h>
#include "util.h"

int Q5_6(void)
{
	int day;
	int sum = 0, count = 0;
	while (scanf_s("%d", &day) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	while (count++ < day)
		sum += (count * count);

	printf("합 : %d\n", sum);

	return 0;
}