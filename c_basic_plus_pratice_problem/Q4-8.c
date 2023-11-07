#include <stdio.h>
#include "util.h"
static void scan_int(int* n);


int Q4_8(void)
{
	int mile;
	int gallon;
	int km;
	int liter;
	const int MILE_TO_KM = 1609;
	const int GALLON_TO_LITER = 3785;

	printf("주행한 거리 입력 (마일) : ");
	scan_int(&mile);
	km = mile * MILE_TO_KM;

	printf("소비한 휘발유 입력 (갤런) : ");
	scan_int(&gallon);
	liter = gallon * GALLON_TO_LITER;

	printf("100킬로 미터당 소비한 휘발유 양(리터) : %.1f", ((double)liter / km) * 100);

	return 0;
}
 
static void scan_int(int* n)
{
	while (scanf_s("%d", n) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	eat_chars();
}