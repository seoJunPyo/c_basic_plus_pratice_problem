#include <stdio.h>
#include "util.h"

int Q5_6(void)
{
	int day;
	int sum = 0, count = 0;
	while (scanf_s("%d", &day) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	while (count++ < day)
		sum += (count * count);

	printf("�� : %d\n", sum);

	return 0;
}