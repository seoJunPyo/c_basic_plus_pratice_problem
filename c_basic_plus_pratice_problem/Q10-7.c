#include <stdio.h>

void reverse_arr(double nums[], int len);
void copy_arr(double target[], double source[], int len);

int Q10_7(void)
{
	double nums[3][10];
	double copy[3][10];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d행 %d번째 요소 입력 : ", i + 1, j + 1);
			while (scanf_s("%lf", &nums[i][j]) != 1)
			{
				printf("실수가 아닙니다.\n");
				printf("다시 입력 :  ");
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		reverse_arr(nums[i], 10);
		copy_arr(copy[i], nums[i], 10);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%f ", nums[i][j]);
		printf("\n");
	}

	return 0;
}

static void reverse_arr(double nums[], int len)
{
	double temp;

	for (int i = 0; i < len / 2; i++)
	{
		temp = nums[i];
		nums[i] = nums[len - i - 1];
		nums[len - i - 1] = temp;
	}
}

static void copy_arr(double target[], double source[], int len)
{
	for (int i = 0; i < len; i++)
		target[i] = source[i];
}