#include <stdio.h>
#include <limits.h>
#include <float.h>

int Q3_2(void)
{
	int code;

	printf("아스키 코드 값 입력 : ");
	scanf_s("%d", &code);
	printf("%d : %c\n", code, code);

	return 0;
}