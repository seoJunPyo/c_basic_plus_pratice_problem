#include <stdio.h>

void copy_2d_arr(double target[][5], double source[][5], int col);
void copy_arr(double target[], double source[], int len);

int Q10_9(void)
{
	double nums[3][5];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d�� %d��° ��� �Է� : ", i + 1, j + 1);
			while (scanf_s("%lf", &nums[i][j]) != 1)
			{
				printf("�Ǽ��� �ƴմϴ�.\n");
				printf("�ٽ� �Է� :  ");
			}
		}
	}
}

static void copy_2d_arr(double target[][5], double source[][5], int col)
{
	for (int i = 0; i < col; i++)
		copy_arr(target[i], source[i], 5);
}

static void copy_arr(double target[], double source[], int len)
{
	for (int i = 0; i < len; i++)
		target[i] = source[i];
}