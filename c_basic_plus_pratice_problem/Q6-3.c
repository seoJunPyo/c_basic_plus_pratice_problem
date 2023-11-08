#include <stdio.h>

int Q6_3(void)
{
	int loop;
	printf("정수 입력 : ");
	while (scanf_s("%d", &loop) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
	}

	for (int i = 0; i <= loop; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf("%c", loop - j + 'A');
		printf("\n");
	}

	return 0;
}