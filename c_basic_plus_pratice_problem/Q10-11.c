#include <stdio.h>

void print_2d_arr(int nums[][5], int col);
void double_2d_arr(int nums[][5], int col);

int Q10_11(void)
{
	int nums_2d[3][5];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
		{
			printf("%d�� %d�� �Է� : ", i + 1, j + 1);
			while (scanf_s("%d", &nums_2d[i][j]) != 1)
			{
				printf("���ڰ� �ƴմϴ�.\n");
				printf("�ٽ� �Է� : ");
			}
		}

	print_2d_arr(nums_2d, 3);
	double_2d_arr(nums_2d, 3);
	printf("\n");
	print_2d_arr(nums_2d, 3);

	return 0;
}

static void print_2d_arr(int nums[][5] , int col)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d�� %d�� : %d  ", i + 1, j + 1, nums[i][j]);
		printf("\n");
	}
}

static void double_2d_arr(int nums[][5], int col)
{
	for (int i = 0; i < col; i++)
		for (int j = 0; j < 5; j++)
			nums[i][j] *= 2;
}