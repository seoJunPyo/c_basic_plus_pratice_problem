#include <stdio.h>

void reverse_arr(double nums[], int len);

int Q10_6(void)
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

	reverse_arr(nums, 10);
	
	for (int i = 0; i < 10; i++)
		printf("%f ", nums[i]);

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