#include <stdio.h>
#include "util.h"

int Q6_10(void)
{
	int start, end;

	printf("������ ���Ѱ� ������ �Է��Ͻÿ�. : ");
	while (scanf_s("%d %d", & start, &end) == 2 && start < end)
	{
		int sum = 0;

		for (int i = start; i <= end; i++)
			sum += i * i;

		printf("%d���� %d����, �������� ���� %d\n", start * start, end * end, sum);
		printf("������ ���Ѱ� ������ �Է��Ͻÿ�. : ");
		eat_chars();
	}

	printf("����!\n");

	return 0;
}

