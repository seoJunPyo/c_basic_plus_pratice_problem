#include <stdio.h>

int power_count_call(int num);

int Q12_4(void)
{
	int i = 0;

	for (i = 0; i < 100; i++)
	{
		printf("함수 결과 : %d\n", power_count_call(i));
	}

	return 0;
}

int power_count_call(int num)
{
	static int count = 0;
	printf("함수 호출 횟수 : %d, ", count++);

	return num * num;
}