#include <stdio.h>
#include "util.h"
#define SIZE 8

int Q6_11(void)
{
	int nums[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d��° ��� �Է� : ", i + 1);
		while (scanf_s("%d", &nums[i]) != 1)
		{
			printf("��ȿ�� ���� �ƴմϴ�.\n");
			printf("�ٽ� �Է� : ");
			eat_chars();
		}

		eat_chars();
	}

	printf("\n");
	for (int i = SIZE - 1; i >= 0; i--)
		printf("%d ", nums[i]);

	return 0;
}