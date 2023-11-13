#include <stdio.h>
#include <limits.h>

int max_idx(double nums[], int len);

int Q10_4(void)
{
	double nums[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d��° ��� �Է� : ", i + 1);
		while (scanf_s("%lf", &nums[i]) != 1)
		{
			printf("�Ǽ��� �ƴմϴ�.\n");
			printf("�ٽ� �Է� :  ");
		}
	}

	printf("�迭 �� �ִ� �ε��� : %d", max_idx(nums, 10));

	return 0;
}

int max_idx(double nums[], int len)
{
	int max_idx = 0;

	for (int i = 1; i < len; i++)
		max_idx = nums[max_idx] > nums[i] ? max_idx : i;

	return max_idx;
}