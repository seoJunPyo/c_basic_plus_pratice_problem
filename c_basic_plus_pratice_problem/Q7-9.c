#include <stdio.h>
#include "util.h"

int Q7_9(void)
{
	int num;

	printf("���� �Է� : ");
	while (scanf_s("%d", &num) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
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