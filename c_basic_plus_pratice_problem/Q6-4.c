#include <stdio.h>

int Q6_4(void)
{
	int loop, count = 0;
	printf("���� �Է� : ");
	while (scanf_s("%d", &loop) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
	}

	for (int i = 0; i <= loop; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf("%c", 'A' + count++);
		printf("\n");
	}

	return 0;
}