#include <stdio.h>
#include "util.h"

double get_cm(void);

int Q5_4(void)
{
	double cm;
	const double CM_TO_FEAT = 30.48;
	const double CM_TO_INCH = 2.54;

	while ((cm = get_cm()) > 0)
		printf("%.1f센티미터는 %.0f피트, %.1f인치입니다.\n", cm, cm / CM_TO_FEAT, cm / CM_TO_INCH);

	return 0;
}

double get_cm(void)
{
	double cm;
	
	printf("센티미터 단위로 키 입력 : ");
	while (scanf_s("%lf", &cm) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	eat_chars();

	return cm;
}