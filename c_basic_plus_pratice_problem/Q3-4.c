#include <stdio.h>

int Q3_4(void)
{
	float num;
	
	printf("실수 입력 : ");
	scanf_s("%f", &num);

	printf("고정소수점 표기 : %f\n", num);
	printf("지수 표기 : %e\n", num);
	printf("p 표기 : %a\n", num);

	return 0;
}