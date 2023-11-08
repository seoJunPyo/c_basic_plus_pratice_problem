#include <stdio.h>
#include "util.h"

int get_day(void);

int Q5_3(void)
{
	int day;
	const int WEEK = 7;
	
	while ((day = get_day()) > 0)
		printf("%d일은 %d주, %d일입니다.\n", day, day / WEEK, day % WEEK);
	
	return 0;
}

int get_day(void)
{
	int day;

	printf("일 입력 : ");

	while (scanf_s("%d", &day) != 1)
	{ 
		printf("잘못된 입력입니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}
	eat_chars();

	return day;
}
