#include <stdio.h>
#define SIZE 8

int Q6_14(void)
{
	double fl_els[SIZE];
	double fl_sums[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d��° ��� �Է� : ", i + 1);
		while (scanf_s("%lf", &fl_els[i]) != 1)
		{
			printf("��ȿ�� ���� �ƴմϴ�. \n");
			printf("�ٽ� �Է� : ");
		}

		fl_sums[i] = i == 0 ? fl_els[i] : fl_sums[i - 1] + fl_els[i];
	}

	for (int i = 0; i < SIZE; i++)
		printf("%-5.2f ", fl_els[i]);

	printf("\n");

	for (int i = 0; i < SIZE; i++)
		printf("%-5.2f ", fl_sums[i]);

	return 0;
}