#include <stdio.h>
#include <ctype.h>
#include "util.h"
#define MAX_TIME 40
#define OVERTIME_PAY BASE_PAY * 1.5
#define GRADE_A 300
#define GRADE_B 150
#define TAX_RATE_A 0.15
#define TAX_RATE_B 0.2
#define TAX_RATE_C 0.25

void print_line(void);
void show_pay(double base_pay);
void show_menu(void);

int Q8_7(void)
{
	char choice;
	double pay_list[] = { 8.75, 9.33, 10.00, 11.20 };
	show_menu();

	while ((choice = tolower(get_first())) !='q')
	{
		switch (choice)
		{
		case 'a':
			show_pay(pay_list[0]);
			break;
		case 'b':
			show_pay(pay_list[1]);
			break;
		case 'c':
			show_pay(pay_list[2]);
			break;
		case 'd':
			show_pay(pay_list[3]);
			break;
		default:
			printf("유효한 선택이 아닙니다.\n");
			break;
		}

		show_menu();
	}

	printf("종료!");

	return 0;
}

static void show_pay(double base_pay)
{
	int work_time;
	double gross_pay, taxes, net_pay;
	double overtime_pay = base_pay * 1.5;

	printf("주간 노동 시간 입력 : ");
	while (scanf_s("%d", &work_time) != 1)
	{
		printf("유효한 값이 아닙나다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	if (work_time <= MAX_TIME)
		gross_pay = work_time * base_pay;
	else
		gross_pay = MAX_TIME * base_pay + (work_time - MAX_TIME) * overtime_pay;

	if (gross_pay <= GRADE_A)
		taxes = gross_pay * TAX_RATE_A;
	else if (gross_pay <= GRADE_A + GRADE_B)
		taxes = GRADE_A * TAX_RATE_A + (gross_pay - GRADE_A) * TAX_RATE_B;
	else
		taxes = GRADE_A * TAX_RATE_A + GRADE_B * TAX_RATE_B + (gross_pay - GRADE_A - GRADE_B) * TAX_RATE_C;

	net_pay = gross_pay - taxes;

	printf("총 소득 : %f\n세금 : %f\n순소득 : %f\n\n", gross_pay, taxes, net_pay);
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
	printf("자신의 기본금에 해당하는 번호를 선택하시오(끝내려면 5번을 선택시오):\n");
	printf("a) %-30s b) %-30s\n", "시간당 $8.75", "시간당 $9.33");
	printf("c) %-30s d) %-30s\n", "시간당 $10.00", "시간당 $11.20");
	printf("q) %-30s\n", "종료");
	print_line();
	printf("\n");
}