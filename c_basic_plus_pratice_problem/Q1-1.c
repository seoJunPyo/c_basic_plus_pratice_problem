#include <stdio.h>

int Q1_1(void)
{
	// 사용자가 입력할 값을 저장할 변수 선언. 
	float inch;

	// 사용자에게 인치 입력을 요구
	printf("센티미터 단위로 변경할 인치 입력 : ");
	scanf_s("%f", &inch);

	// 입력된 값을 센티미로 변환하여 출력
	printf("%f인치는 %f센티미터 입니다.", inch, inch * 2.54);

	return 0;
}