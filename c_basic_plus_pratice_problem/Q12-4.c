#include <stdio.h>

int power_count_call(int num);

int Q12_4(void)
{
	int i = 0;

	for (i = 0; i < 100; i++)
	{
		printf("�Լ� ��� : %d\n", power_count_call(i));
	}

	return 0;
}

int power_count_call(int num)
{
	static int count = 0;
	printf("�Լ� ȣ�� Ƚ�� : %d, ", count++);

	return num * num;
}