#include <stdio.h>
#include <float.h>

double max_min_interval(double nums[], int len);

int Q10_5(void)
{
	double nums[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 요소 입력 : ", i + 1);
		while (scanf_s("%lf", &nums[i]) != 1)
		{
			printf("실수가 아닙니다.\n");
			printf("다시 입력 :  ");
		}
	}

	printf("배열 중 최댓값과 최솟값의 차이 : %f", max_min_interval(nums, 10));

	return 0;
}

double max_min_interval(double nums[], int len)
{
	double max = DBL_MIN;
	double min = DBL_MAX;

	for (int i = 1; i < len; i++)
	{
		max = max > nums[i] ? max : nums[i];
		min = min > nums[i] ? nums[i] : min;
	}

	return max - min;
}