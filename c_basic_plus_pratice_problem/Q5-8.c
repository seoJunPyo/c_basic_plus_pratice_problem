#include <stdio.h>
#include "util.h"

int scan_num(int* num);

int Q5_8(void)
{
	int numA, numB;

	printf("이 프로그램은 모듈러스를 구하는 프로그램이다.\n");
	printf("두 번째 피연산자로 제공할 정수를 입력하시오. : ");
	scan_num(&numA);

	printf("이제 첫번째 피연산자를 입력하시오. : ");
	while (scan_num(&numB) == 1 && numB > 0)
	{
		printf("%d %% %d = %d\n", numA, numB, numA % numB);
		printf("첫번째 피연산자용(<= 0 이면 종료) 다음 수를 입력하시오. : ");
	}

	printf("종료.\n");

	return 0;
}

static int scan_num(int* num)
{
	int status;

	while ((status = scanf_s("%d", num)) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	eat_chars();

	return status;
}