#include <stdio.h>
#include "util.h"

int Q5_2(void)
{
	int num;

	printf("���� �Է� : ");
	while (scanf_s("%d", &num) != 1)
	{
		printf("��ȿ���� ���� �Է��Դϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	for (int i = num; i <= num + 10; i++)
		printf("%d ", i);

	return 0;
}