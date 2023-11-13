#include <stdio.h>

static void to_base_n(int digit, int notation);
static void scan_int(int* n);

char numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int Q9_10(void)
{
	int digit, notation;

	printf("십진수 입력 : ");
	scan_int(&digit);
	printf("변경할 진법 입력 : ");
	scan_int(&notation);

	printf("%d을 %d진법으로 변경한 결과 : ", digit, notation);
	to_base_n(digit, notation);
	
	return 0;
}

static void to_base_n(int digit, int notation)
{
	int rest;

	rest = digit % notation;
	if (digit >= notation)
		to_base_n(digit / notation, notation);
	putchar(numbers[rest]);

	return;
}

static void scan_int(int* n)
{
	while (scanf_s("%d", n) != 1)
	{
		printf("숫자가 아닙니다.\n");
		printf("다시 입력 : ");
	}
}