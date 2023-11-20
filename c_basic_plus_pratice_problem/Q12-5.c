#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define SIZE 100

void insert_sort(int nums[], int len);
void bubble_sort(int nums[], int len);

int Q12_5(void)
{
	int rand_nums[SIZE];
	time_t t;
	struct tm tm;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < SIZE; i++)
		rand_nums[i] = (rand() % 10) + 1;



	t = time(NULL);
	localtime_s(&tm, &t);
	printf("[start] m : %d, s : %d\n", tm.tm_min, tm.tm_sec);

	insert_sort(rand_nums, SIZE);

	t = time(NULL);
	localtime_s(&tm, &t);
	printf("[end] m : %d, s : %d\n", tm.tm_min, tm.tm_sec);

	for (int i = 0; i < SIZE; i++)
		printf("%d ", rand_nums[i]);
	printf("\n");

	return 0;
}

void insert_sort(int nums[], int len)
{
	int temp;

	for (int i = 1; i < len; i++)
	{
		if (nums[i - 1] >= nums[i])
			continue;

		temp = nums[i];
		for (int j = 0; j < i; j++)
			if (nums[j] < temp)
			{
				memmove(&nums[j + 1], &nums[j], sizeof(nums[0]) * (i - j));
				nums[j] = temp;
				break;
			}
	}
}

void bubble_sort(int nums[], int len)
{
	int temp;

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - 1 - i; j++)
			if (nums[j] < nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
}