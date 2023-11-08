#include <stdio.h>
#include "util.h"

static int scan_num(int*);

int Q6_6(void)
{
	int start, end;

	printf("시작할 정수 입력 : ");
	scan_num(&start);
	printf("끝낼 정수 입력 : ");
	scan_num(&end);

	for (int i = start; i <= end; i++)
		printf("%d - 제곱 : %d, 세제곱 : %d\n", i, i * i, i * i * i);

	return 0;
}

static int scan_num(int* num)
{
	int status;

	while ((status = scanf_s("%d", num)) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	eat_chars();

	return status;
}