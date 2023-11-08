#include <stdio.h>
#include "util.h"

int scan_num(int* num);

int Q5_8(void)
{
	int numA, numB;

	printf("�� ���α׷��� ��ⷯ���� ���ϴ� ���α׷��̴�.\n");
	printf("�� ��° �ǿ����ڷ� ������ ������ �Է��Ͻÿ�. : ");
	scan_num(&numA);

	printf("���� ù��° �ǿ����ڸ� �Է��Ͻÿ�. : ");
	while (scan_num(&numB) == 1 && numB > 0)
	{
		printf("%d %% %d = %d\n", numA, numB, numA % numB);
		printf("ù��° �ǿ����ڿ�(<= 0 �̸� ����) ���� ���� �Է��Ͻÿ�. : ");
	}

	printf("����.\n");

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