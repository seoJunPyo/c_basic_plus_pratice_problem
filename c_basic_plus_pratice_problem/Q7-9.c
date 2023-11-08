#include <stdio.h>
#include "util.h"

int Q7_9(void)
{
	int num;

	printf("정수 입력 : ");
	while (scanf_s("%d", &num) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
	}

	for (int i = 2; i <= num; i++)
	{
		int is_frame = 1;

		for (int j = 2; j * j <= i; j++)
			if (i % j == 0)
			{
				is_frame = 0;
				break;
			}

		if (is_frame == 1)
			printf("%d ", i);
	}

	return 0;
}