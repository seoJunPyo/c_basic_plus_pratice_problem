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
			printf("��ȿ���� ���� �����Դϴ�.\n");
			printf("�ٽ� �Է� : ");
			continue;
		}

		printf("ù ��° ���� �Է��Ͻÿ� : ");
		get_fl(&flA);
		printf("�� ��° ���� �Է��Ͻÿ� : ");
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
				printf("0���� ���� �� �����ϴ�.\n");
				printf("���ο� �� �Է� : ");
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
		printf(": ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
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
	printf("���ϴ� ���꿡 �ش��ϴ� ���ڸ� �����Ͻÿ�(�������� q) : \n");
	printf("a) %-30s s) %-30s\n", "add(����)", "subtract(�E��)");
	printf("m) %-30s d) %-30s\n", "multiply(����)", "devide(������)");
	printf("q) %-30s\n", "����");
	print_line();
	printf("\n");
}

static void print_string(void)
{
	char ch;
	while ((ch = getchar()) != '\n')
		printf("%c", ch);
}