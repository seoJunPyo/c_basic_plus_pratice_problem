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

	printf("�� ���� �Է� : ");
	while (scanf_s("%d %d", &a, &b) != 2)
	{
		printf("�� ���� ���� �Է� : ");
		eat_chars();
	}

	printf("a) %-20s b) %-20s\n", "����", "����");
	printf("c) %-20s d) %-20s\n", "����", "������");
	while ((choice = get_first()) < 'a' || choice > 'd')
		printf("��ȿ���� ���� �Է��Դϴ�. �ٽ� ���� : ");
	
	result = fp[choice - 'a'](a, b);
	printf("��� : %d\n", result);

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

