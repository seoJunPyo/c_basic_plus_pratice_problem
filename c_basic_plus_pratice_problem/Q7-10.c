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
	printf("���� : ");
	while (scanf_s("%d", &choice) == 1 && choice != 5)
	{
		eat_chars();
		if (choice > 5 || choice < 1)
		{
			printf("��ȿ�� ������ �ƴմϴ�!\n");
			printf("�ٽ� ���� : ");
			continue;
		}
		
		printf("����� �ҵ��� �Է� : ");
		while (scanf_s("%d", &income) != 1)
		{
			printf("��ȿ�� ���� �ƴմϴ�.\n");
			printf("�ٽ� �Է� : ");
			eat_chars();
		}
		eat_chars();

		show_tax(income, max_income[choice - 1]);

		show_category_menu();
		printf("���� : ");
	}

	printf("����!\n");

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
	printf("%-30s%-70s\n", "���� ����", "����");
	print_line();
	printf("%-30s%-70s\n", "1) ����", "$17,850���� 15%, �ʰ����� 28%");
	printf("%-30s%-70s\n", "2) ����", "$23,900���� 15%, �ʰ����� 28%");
	printf("%-30s%-70s\n", "3) �¹���, �ջ�", "$29,750���� 15%, �ʰ����� 28%");
	printf("%-30s%-70s\n", "4) �¹���, ����", "$14,875���� 15%, �ʰ����� 28%");
	printf("%-30s\n", "5) ����");
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

	printf("����� �ҵ漼�� $%.2f�Դϴ�.\n", tax);
}