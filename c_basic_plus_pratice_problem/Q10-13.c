#include <stdio.h>
#include <limits.h>

double get_average_col(int nums[], int len);
double get_average_total(int nums[][5], int col, int row);
int get_2d_nums_max(int nums[][5], int col, int row);

int Q10_13(void)
{
	int nums_2d[3][5];
	double averages[3];
	double total_average;
	int max;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
		{
			printf("%d행 %d열 입력 : ", i + 1, j + 1);
			while (scanf_s("%d", &nums_2d[i][j]) != 1)
			{
				printf("숫자가 아닙니다.\n");
				printf("다시 입력 : ");
			}
		}

	for (int i = 0; i < 3; i++)
		averages[i] = get_average_col(nums_2d[i], 5);
	total_average = get_average_total(nums_2d, 3, 5);
	max = get_2d_nums_max(nums_2d, 3, 5);

	for (int i = 0; i < 3; i++)
		printf("%d번째열 평균 :  %f\n", i + 1, averages[i]);
	printf("전체 평균 : %f\n", total_average);
	printf("최댓값 : %d\n", max);

	return 0;
}
 
static double get_average_col(int nums[], int len)
{
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += nums[i];

	return (double)sum / len;
}

static double get_average_total(int nums[][5], int col, int row)
{
	int sum = 0;

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			sum += nums[i][j];
		
	return (double)sum / (col * row);
}

static int get_2d_nums_max(int nums[][5], int col, int row)
{
	int max = INT_MIN;

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			max = max > nums[i][j] ? max : nums[i][j];

	return max;
}