#include <stdio.h>
#include "util.h"

int Q6_10(void)
{
	int start, end;

	printf("정수의 하한과 상한을 입력하시오. : ");
	while (scanf_s("%d %d", & start, &end) == 2 && start < end)
	{
		int sum = 0;

		for (int i = start; i <= end; i++)
			sum += i * i;

		printf("%d부터 %d까지, 제곱들의 합은 %d\n", start * start, end * end, sum);
		printf("정수의 하한과 상한을 입력하시오. : ");
		eat_chars();
	}

	printf("종료!\n");

	return 0;
}

