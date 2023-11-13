#include <stdio.h>
#include <limits.h>

int max(int nums[], int len);

int Q10_3(void)
{
	int nums[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d��° ��� �Է� : ", i + 1);
		while (scanf_s("%d", &nums[i]) != 1)
		{
			printf("���ڰ� �ƴմϴ�.\n");
			printf("�ٽ� �Է� :  ");
		}
	}

	printf("�迭 �� �ִ� : %d", max(nums, 10));

	return 0;
}

int max(int nums[], int len)
{
	int max = INT_MIN;

	for (int i = 0; i < len; i++)
		max = nums[i] > max ? nums[i] : max;

	return max;
}