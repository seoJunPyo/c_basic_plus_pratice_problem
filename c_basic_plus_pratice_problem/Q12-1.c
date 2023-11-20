#include <stdio.h>

void critic(int* units);

int Q12_1(void)
{
	int units;

	printf("버터 한 통 가격이 몇 파운드인지 아세요?\n");
	scanf_s("%d", &units);
	while (units != 56)
		critic(&units);
	printf("가격을 알고 있었군요!\n");

	return 0;
}

void critic(int * units)
{
	printf("틀렸습니다. 다시 맞춰보세요!\n");
	scanf_s("%d", units);
}