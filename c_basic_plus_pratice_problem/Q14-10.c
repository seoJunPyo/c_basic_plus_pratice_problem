#include <stdio.h>
#include "util.h"

int sum(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

int Q14_10(void)
{
	int (*fp[4])(int, int) = { sum ,subtraction, multiplication, division };
	char choice; 
	int a, b, result;

	printf("두 정수 입력 : ");
	while (scanf_s("%d %d", &a, &b) != 2)
	{
		printf("두 개의 정수 입력 : ");
		eat_chars();
	}

	printf("a) %-20s b) %-20s\n", "덧셈", "뺄셈");
	printf("c) %-20s d) %-20s\n", "곱셈", "나눗셈");
	while ((choice = get_first()) < 'a' || choice > 'd')
		printf("유효하지 않은 입력입니다. 다시 선택 : ");
	
	result = fp[choice - 'a'](a, b);
	printf("결과 : %d\n", result);

	return 0;
}

int sum(int a, int b)
{
	return a + b;
}

int subtraction(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	return a / b;
}

