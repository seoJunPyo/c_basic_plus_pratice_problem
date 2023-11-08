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
	char* products_name[SIZE] = { "아티초코", "비트" ,"당근" };

	show_product_list();
	printf("구매할 상품 선택 (종료하려면 q) : ");
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
		printf("추가 구매할 상품 선택 (종료하려면 q) : ");
	}
	show_cart(products_name, products);
	printf("종료!\n");

	return 0;
}

void show_product_list(void)
{
	print_line();
	printf("상품 목록 : \n");
	printf("%-30s%-70s\n", "a) 아티초크", "1파운드당 $2.05");
	printf("%-30s%-70s\n", "b) 비트", "1파운드당 $1.15");
	printf("%-30s%-70s\n", "c) 당근", "1파운드당 $1.09");
	print_line();
	printf("배송비 : \n");
	printf("%-30s%-70s\n", "5파운드 미만", "$6.50");
	printf("%-30s%-70s\n", "5파운드 이상 20파운드 미만", "$14.00");
	printf("%-30s%-70s\n", "20파운드 이상", "$14.00에 파운드당 $0.05 파운드 추가");
	print_line();
	printf("$100이상 주문 시, 5%% 할인!\n");
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
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	eat_chars();

	return choice;
}

void add_cart(char* product_name, int *product)
{
	int count;

	printf("%s 구매 수량 선택 : ", product_name);
	while (scanf_s("%d", &count) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}
	(*product) += count;
	printf("%s, %d개 장바구니에 추가!\n", product_name, count);
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
	printf("%-30s%-30s%-40s\n", "품목", "구매 수량", "총액");
	for (int i = 0; i < SIZE; i++)
		printf("%-30s%-30d$%-39.2f\n", product_names[i], products[i], product_totals[i]);
	print_line();
	printf("%-30s%-30s$%-39s\n", "전체 총액", "할인 가격", "배송비");
	printf("$%-29.2f$%-29.2f$%-39.2f\n", total, discount, dilivery_pee);
	print_line();
	printf("%-60s$%-39.2f\n", "총액 : ", total - discount + dilivery_pee);
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