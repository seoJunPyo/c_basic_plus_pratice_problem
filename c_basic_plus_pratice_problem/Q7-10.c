#include <stdio.h>
#include "util.h"

void print_line(void);
void show_category_menu(void);
void show_tax(int income, int max_income);

const double BASE_TAX = 0.15;
const double OVER_TAX = 0.28;

int Q7_10(void)
{
	int choice, income;
	int max_income[4] = { 17850, 23900, 29750, 14875 };

	show_category_menu();
	printf("선택 : ");
	while (scanf_s("%d", &choice) == 1 && choice != 5)
	{
		eat_chars();
		if (choice > 5 || choice < 1)
		{
			printf("유효한 선택이 아닙니다!\n");
			printf("다시 선택 : ");
			continue;
		}
		
		printf("당신의 소득을 입력 : ");
		while (scanf_s("%d", &income) != 1)
		{
			printf("유효한 값이 아닙니다.\n");
			printf("다시 입력 : ");
			eat_chars();
		}
		eat_chars();

		show_tax(income, max_income[choice - 1]);

		show_category_menu();
		printf("선택 : ");
	}

	printf("종료!\n");

	return 0;
}

static void print_line(void)
{
	for (int i = 0; i < 100; i++)
		printf("-");
	printf("\n");
}

void show_category_menu(void)
{
	printf("\n");
	print_line();
	printf("%-30s%-70s\n", "과세 구분", "세율");
	print_line();
	printf("%-30s%-70s\n", "1) 독신", "$17,850까지 15%, 초과분은 28%");
	printf("%-30s%-70s\n", "2) 가장", "$23,900까지 15%, 초과분은 28%");
	printf("%-30s%-70s\n", "3) 맞벌이, 합산", "$29,750까지 15%, 초과분은 28%");
	printf("%-30s%-70s\n", "4) 맞벌이, 별산", "$14,875까지 15%, 초과분은 28%");
	printf("%-30s\n", "5) 종료");
	print_line();
	printf("\n");
}

void show_tax(int income, int max_income)
{
	double tax;
	
	if (income <= max_income)
		tax = (double)income * BASE_TAX;
	else
		tax = (double)max_income * BASE_TAX + (double)(income - max_income) * OVER_TAX;

	printf("당신의 소득세는 $%.2f입니다.\n", tax);
}