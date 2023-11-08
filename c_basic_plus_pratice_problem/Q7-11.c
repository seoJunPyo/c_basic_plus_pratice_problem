#include <stdio.h>
#include <ctype.h>
#include "util.h"
#define SIZE 3

void print_line(void);
void show_product_list(void);
int get_choice(void);
void add_cart(char* product_name, int* product);
double calc_dilivery_pee(double total);
void show_cart(char* product_names[], int products[]);

int Q7_11(void)
{
	int choice;
	int products[SIZE] = { 0, 0 ,0 };
	char* products_name[SIZE] = { "��Ƽ����", "��Ʈ" ,"���" };

	show_product_list();
	printf("������ ��ǰ ���� (�����Ϸ��� q) : ");
	while ((choice = get_choice()) && choice != 'q')
	{
		switch (choice)
		{
		case 'a' :
			add_cart(products_name[0], &products[0]);
			break;
		case 'b':
			add_cart(products_name[1], &products[1]);
			break;
		case 'c':
			add_cart(products_name[2], &products[2]);
			break;
		default:
			break;
		}

		eat_chars();

		show_product_list();
		printf("�߰� ������ ��ǰ ���� (�����Ϸ��� q) : ");
	}
	show_cart(products_name, products);
	printf("����!\n");

	return 0;
}

void show_product_list(void)
{
	print_line();
	printf("��ǰ ��� : \n");
	printf("%-30s%-70s\n", "a) ��Ƽ��ũ", "1�Ŀ��� $2.05");
	printf("%-30s%-70s\n", "b) ��Ʈ", "1�Ŀ��� $1.15");
	printf("%-30s%-70s\n", "c) ���", "1�Ŀ��� $1.09");
	print_line();
	printf("��ۺ� : \n");
	printf("%-30s%-70s\n", "5�Ŀ�� �̸�", "$6.50");
	printf("%-30s%-70s\n", "5�Ŀ�� �̻� 20�Ŀ�� �̸�", "$14.00");
	printf("%-30s%-70s\n", "20�Ŀ�� �̻�", "$14.00�� �Ŀ��� $0.05 �Ŀ�� �߰�");
	print_line();
	printf("$100�̻� �ֹ� ��, 5%% ����!\n");
	print_line();
}

static void print_line(void)
{
	for (int i = 0; i < 100; i++)
		printf("-");
	printf("\n");
}

int get_choice(void)
{
	char choice;
	
	while (scanf_s("%c", &choice, 1) != 1 || (choice = tolower(choice)) != 'a' && choice != 'b' && choice != 'c' && choice != 'q')
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	eat_chars();

	return choice;
}

void add_cart(char* product_name, int *product)
{
	int count;

	printf("%s ���� ���� ���� : ", product_name);
	while (scanf_s("%d", &count) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}
	(*product) += count;
	printf("%s, %d�� ��ٱ��Ͽ� �߰�!\n", product_name, count);
}

void show_cart(char* product_names[], int products[])
{
	const double DISCOUNT_RATE = 0.05;
	double product_price[SIZE] = { 2.05, 1.15, 1.09 };
	double product_totals[SIZE];
	double total = 0, discount = 0, dilivery_pee = 0;

	for (int i = 0; i < SIZE; i++)
	{
		product_totals[i] = (double)products[i] * product_price[i];
		total += product_totals[i];
	}

	discount = total >= 100 ?  total * DISCOUNT_RATE : 0;
	dilivery_pee = calc_dilivery_pee(total);

	print_line();
	printf("%-30s%-30s%-40s\n", "ǰ��", "���� ����", "�Ѿ�");
	for (int i = 0; i < SIZE; i++)
		printf("%-30s%-30d$%-39.2f\n", product_names[i], products[i], product_totals[i]);
	print_line();
	printf("%-30s%-30s$%-39s\n", "��ü �Ѿ�", "���� ����", "��ۺ�");
	printf("$%-29.2f$%-29.2f$%-39.2f\n", total, discount, dilivery_pee);
	print_line();
	printf("%-60s$%-39.2f\n", "�Ѿ� : ", total - discount + dilivery_pee);
	print_line();
}

double calc_dilivery_pee(double total)
{
	const double peeA = 6.50, peeB = 14.00, extra_pee = 0.50;
	const int lineA = 5, lineB = 20;
	double pee;

	if (total < lineA)
		pee = peeA;
	else if (total < lineB)
		pee = peeB;
	else
		pee = peeB + (total - lineB) * extra_pee;

	return pee;
}