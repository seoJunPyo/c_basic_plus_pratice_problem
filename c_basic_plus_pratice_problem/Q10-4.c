#include <stdio.h>
#include <limits.h>

int max_idx(double nums[], int len);

int Q10_4(void)
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

	printf("배열 중 최댓값 인덱스 : %d", max_idx(nums, 10));

	return 0;
}

int max_idx(double nums[], int len)
{
	int max_idx = 0;

	for (int i = 1; i < len; i++)
		max_idx = nums[max_idx] > nums[i] ? max_idx : i;

	return max_idx;
}