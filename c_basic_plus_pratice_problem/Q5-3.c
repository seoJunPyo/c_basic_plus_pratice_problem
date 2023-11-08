#include <stdio.h>
#include "util.h"

int get_day(void);

int Q5_3(void)
{
	int day;
	const int WEEK = 7;
	
	while ((day = get_day()) > 0)
		printf("%d���� %d��, %d���Դϴ�.\n", day, day / WEEK, day % WEEK);
	
	return 0;
}

int get_day(void)
{
	int day;

	printf("�� �Է� : ");

	while (scanf_s("%d", &day) != 1)
	{ 
		printf("�߸��� �Է��Դϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}
	eat_chars();

	return day;
}
