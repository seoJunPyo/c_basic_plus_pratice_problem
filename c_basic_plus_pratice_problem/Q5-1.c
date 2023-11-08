#include <stdio.h>
#include "util.h"

int Q5_1(void)
{
	int min, hour;
	const int HOUR = 60;

	printf("분 입력 : ");
	while (scanf_s("%d", &min) == 1 && min > 0)
	{
		hour = min / HOUR;
		min = min % HOUR;

		printf("%d시 %d분\n", hour, min);
		eat_chars();

		printf("분 입력 : ");
	}
	
	return 0;
}