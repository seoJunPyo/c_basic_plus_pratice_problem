#include <stdio.h>

int Q3_5(void)
{
	int age;
	const double YEAR_SECONDS = 3.156E7;
	printf("당신의 나이 입력 : ");
	scanf_s("%d", &age);

	printf("%d살은 대략 %f초 살았습니다.\n", age, age * YEAR_SECONDS);

	return 0;
}