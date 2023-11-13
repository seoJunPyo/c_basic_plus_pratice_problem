#include <stdio.h>
#include <limits.h>

int max(int nums[], int len);

int Q10_3(void)
{
	int nums[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 요소 입력 : ", i + 1);
		while (scanf_s("%d", &nums[i]) != 1)
		{
			printf("숫자가 아닙니다.\n");
			printf("다시 입력 :  ");
		}
	}

	printf("배열 중 최댓값 : %d", max(nums, 10));

	return 0;
}

int max(int nums[], int len)
{
	int max = INT_MIN;

	for (int i = 0; i < len; i++)
		max = nums[i] > max ? nums[i] : max;

	return max;
}