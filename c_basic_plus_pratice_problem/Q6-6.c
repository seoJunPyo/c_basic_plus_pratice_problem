#include <stdio.h>
#include "util.h"

static int scan_num(int*);

int Q6_6(void)
{
	int start, end;

	printf("������ ���� �Է� : ");
	scan_num(&start);
	printf("���� ���� �Է� : ");
	scan_num(&end);

	for (int i = start; i <= end; i++)
		printf("%d - ���� : %d, ������ : %d\n", i, i * i, i * i * i);

	return 0;
}

static int scan_num(int* num)
{
	int status;

	while ((status = scanf_s("%d", num)) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	eat_chars();

	return status;
}