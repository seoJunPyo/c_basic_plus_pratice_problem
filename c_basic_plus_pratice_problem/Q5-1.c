#include <stdio.h>
#include "util.h"

int Q5_1(void)
{
	int min, hour;
	const int HOUR = 60;

	printf("�� �Է� : ");
	while (scanf_s("%d", &min) == 1 && min > 0)
	{
		hour = min / HOUR;
		min = min % HOUR;

		printf("%d�� %d��\n", hour, min);
		eat_chars();

		printf("�� �Է� : ");
	}
	
	return 0;
}