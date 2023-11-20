#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int roll_dice(int dice, int sides);

int Q12_7(void)
{
	int roll_count, dice, sides;
	srand((unsigned int)time(NULL));

	printf("���� Ƚ���� �Է��Ͻÿ�(�������� q).\n");
	while (scanf_s("%d", &roll_count) == 1 && roll_count != 'q')
	{
		printf("�ֻ��� ����� ���� �ֻ��� ������ �Է��Ͻÿ�(�������� 0) \n");
		while (scanf_s("%d", &sides) != 1) 
		{
			printf("��ȿ�� ���� �ƴմϴ�.\n");
			printf("�ٽ� �Է� : ");
		}

		if (sides <= 0)
			break;

		while (scanf_s("%d", &dice) != 1)
		{
			printf("��ȿ�� ���� �ƴմϴ�.\n");
			printf("�ٽ� �Է� : ");

			while (getchar() != '\n')
				continue;
		}

		for (int i = 0; i < roll_count; i++)
		{
			printf("%d ", roll_dice(dice, sides));
			if (i % 5 == 0)
				printf("\n");
		}
		printf("\n");


		while (getchar() != '\n')
			continue;
		printf("���� Ƚ���� �Է��Ͻÿ�(�������� q).\n");
	}

	printf("����!\n");

	return 0;
}

int roll_dice(int dice, int sides)
{
	int result = 0;

	for (int i = 0; i < dice; i++)
		result += (rand() % sides) + 1;

	return result;
}