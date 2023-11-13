#include <stdio.h>

static void to_base_n(int digit, int notation);
static void scan_int(int* n);

char numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int Q9_10(void)
{
	int digit, notation;

	printf("������ �Է� : ");
	scan_int(&digit);
	printf("������ ���� �Է� : ");
	scan_int(&notation);

	printf("%d�� %d�������� ������ ��� : ", digit, notation);
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
		printf("���ڰ� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
	}
}