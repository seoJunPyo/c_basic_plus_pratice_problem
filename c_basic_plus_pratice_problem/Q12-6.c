#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define SIZE 11

int Q12_6(void)
{
	int rand_nums[SIZE];
	
	memset(rand_nums, 0, 11 * sizeof(int));
	srand((unsigned int)time(NULL));

	for (int j = 0; j < 10; j++)
	{
		printf("%d번째 출력...\n", j + 1);

		for (int i = 0; i < 1000; i++)
			rand_nums[rand() % 10 + 1]++;

		for (int i = 0; i < 10; i++)
			printf("[%d] : %d\n", i + 1, rand_nums[i + 1]);

		printf("\n");
	}

	return 0;
}