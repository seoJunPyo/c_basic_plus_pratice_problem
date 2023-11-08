#include <stdio.h>
#include "util.h"

int Q5_2(void)
{
	int num;

	printf("정수 입력 : ");
	while (scanf_s("%d", &num) != 1)
	{
		printf("유효하지 않은 입력입니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	for (int i = num; i <= num + 10; i++)
		printf("%d ", i);

	return 0;
}