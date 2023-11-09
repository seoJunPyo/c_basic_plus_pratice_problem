#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

void get_fl(float* fl);
void print_line(void);
void show_menu(void);
void print_string(void);

int Q8_8(void)
{
	float flA, flB;
	char choice;

	show_menu();
	while ((choice = tolower(get_first())) != 'q')
	{
		if (!strstr("asmd", (char[2]) { choice, '\0' }))
		{
			printf("유효하지 않은 선택입니다.\n");
			printf("다시 입력 : ");
			continue;
		}

		printf("첫 번째 수를 입력하시오 : ");
		get_fl(&flA);
		printf("두 번째 수를 입력하시오 : ");
		get_fl(&flB);

		switch (choice)
		{
		case 'a':
			printf("%f + %f = %f\n", flA, flB, flA + flB);
			break;
		case 's':
			printf("%f - %f = %f\n", flA, flB, flA - flB);
			break;
		case 'm':
			printf("%f * %f = %f\n", flA, flB, flA * flB);
			break;
		case 'd':
			if (flB == 0)
			{
				printf("0으로 나눌 수 없습니다.\n");
				printf("새로운 수 입력 : ");
				get_fl(&flB);
			}
			printf("%f / %f = %f\n", flA, flB, flA / flB);
			break;
		}

		show_menu();
	}


	return 0;
}

static void get_fl(float* fl)
{
	while (scanf_s("%f", fl) != 1)
	{
		print_string();
		printf(": 수가 아닙니다.\n");
		printf("다시 입력 : ");
	}
}

static void print_line(void)
{
	for (int i = 0; i < 100; i++)
		printf("*");
	printf("\n");
}

static void show_menu(void)
{
	printf("\n");
	print_line();
	printf("원하는 연산에 해당하는 문자를 선택하시오(끝내려면 q) : \n");
	printf("a) %-30s s) %-30s\n", "add(덧셈)", "subtract(뺼셈)");
	printf("m) %-30s d) %-30s\n", "multiply(곱셈)", "devide(나눗셈)");
	printf("q) %-30s\n", "종료");
	print_line();
	printf("\n");
}

static void print_string(void)
{
	char ch;
	while ((ch = getchar()) != '\n')
		printf("%c", ch);
}