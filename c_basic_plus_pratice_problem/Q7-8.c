#include <stdio.h>
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

int Q7_8(void)
{
	int choice;
	double pay_list[] = { 8.75, 9.33, 10.00, 11.20 };
	show_menu();

	while (scanf_s("%d", &choice) == 1 && choice != 5)
	{
		eat_chars();

		switch (choice)
		{
		case 1 :
			show_pay(pay_list[0]);
			break;
		case 2:
			show_pay(pay_list[1]);
			break;
		case 3:
			show_pay(pay_list[2]);
			break;
		case 4:
			show_pay(pay_list[3]);
			break;
		default:
			break;
		}

		show_menu();
	}

	printf("����!");

	return 0;
}

static void show_pay(double base_pay)
{
	int work_time;
	double gross_pay, taxes, net_pay;
	double overtime_pay = base_pay * 1.5;

	printf("�ְ� �뵿 �ð� �Է� : ");
	while (scanf_s("%d", &work_time) != 1)
	{
		printf("��ȿ�� ���� �ƴճ���.\n");
		printf("�ٽ� �Է� : ");
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

	printf("�� �ҵ� : %f\n���� : %f\n���ҵ� : %f\n\n", gross_pay, taxes, net_pay);
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
	printf("�ڽ��� �⺻�ݿ� �ش��ϴ� ��ȣ�� �����Ͻÿ�(�������� 5���� ���ýÿ�):\n");
	printf("1) %-30s 2) %-30s\n", "�ð��� $8.75", "�ð��� $9.33");
	printf("3) %-30s 4) %-30s\n", "�ð��� $10.00", "�ð��� $11.20");
	printf("5) %-30s\n", "����");
	print_line();
	printf("\n");
}