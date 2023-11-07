#include <stdio.h>

int Q4_3(void)
{
	double num;
	
	printf("실수 입력 : ");
	scanf_s("%lf", &num);


	printf("입력된 것은 %.1f 또는 %.1e이다.\n", num, num);

	return 0;
}