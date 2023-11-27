#include "Q17.h"

int binary_search_arr(int nums[], int arr_len, int target);

int Q17_6(void)
{
	int nums[] = { 1 ,3 ,5, 9 , 11, 13, 15, 17 , 19 };
	int target;

	printf("찾을 숫자 : ");
	scanf_s("%d", &target);

	if (binary_search_arr(nums, 9, target) == 1)
	{
		puts("찾았습니다.");
	}
	else
	{
		puts("못 찾았습니다.");
	}

	return 0;
}

int binary_search_arr(int nums[], int arr_len, int target)
{
	int min = 0, max = arr_len;
	int middle_idx = arr_len / 2;

	while (1)
	{
		printf("max : %d, min : %d, mid : %d\n", max, min, middle_idx);
		if (nums[middle_idx] == target)
			return 1;

		if (max - min <= 1)
			return 0;

		if (nums[middle_idx] > target)
			max = middle_idx;
		else
			min = middle_idx;

		middle_idx = ((max - min) / 2) + min;
	}
}