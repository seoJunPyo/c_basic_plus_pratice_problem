#include <stdio.h>

const int YEAR_DAYS = 365;

int Q2_3(void)
{
	int age_years;
	int age_days;

	printf("자신의 나이 입력 : ");
	scanf_s("%d", &age_years);
	age_days = age_years * YEAR_DAYS;

	printf("%d년생은 대략 %d일 살았습니다.\n", age_years, age_days);

	return 0;
}