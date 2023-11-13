#include <stdio.h>
#include <stdlib.h>

void scan_nums(int nums[], int len);
void sum_nums(int sums[], int nums1[], int nums2[], int len);

int Q10_10(void)
{
	int size;
	int* arr1, *arr2, *sums;

	printf("배열 최대 요소 갯수 입력 : ");
	while (scanf_s("%d", &size) != 1)
	{
		printf("숫자가 아닙니다.\n");
		printf("다시 입력 : ");
	}

	arr1 = (int*)malloc(sizeof(int) * size);
	arr2 = (int*)malloc(sizeof(int) * size);
	sums = (int*)malloc(sizeof(int) * size);

	if (arr1 == NULL || arr2 == NULL || sums == NULL)
	{
		printf("배열을 저장할 메모리가 없습니다.");
		exit(EXIT_FAILURE);
	}

	printf("첫번쨰 배열\n");
	scan_nums(arr1, size);
	printf("두번쨰 배열\n");
	scan_nums(arr2, size);

	sum_nums(sums, arr1, arr2, size);
	
	for (int i = 0; i < size; i++)
		printf("%d ", sums[i]);

	return 0;
}

static void scan_nums(int nums[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d번째 요소 입력 : ", i + 1);
		while (scanf_s("%d", &nums[i]) != 1)
		{
			printf("숫자가 아닙니다.\n");
			printf("다시 입력 : ");
		}
	}
}

static void sum_nums(int sums[], int nums1[], int nums2[], int len)
{
	for (int i = 0; i < len; i++)
		sums[i] = nums1[i] + nums2[i];
}
