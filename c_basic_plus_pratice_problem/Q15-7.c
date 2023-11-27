#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include "util.h"
#include "Q15.h"

void show_text_style_us(unsigned long ptext);
long change_ID_us(unsigned long ptext);
void change_size_us(unsigned long ptext);
void change_align_us(unsigned long ptext);
void toggle_opt(unsigned long ptext, int offset);

struct text_style {
	unsigned long ID : 8;
	unsigned long size : 7;
	unsigned long align : 2;
	unsigned long bold : 1;
	unsigned long itelic : 1;
	unsigned long underline : 1;
};

union Text_props {
	struct text_style st_text;
	unsigned long us_text;
};

static char* align[3] = { "����", "���", "������" };
static char* On_and_Off[2] = { "Off", "On" };

int Q15_7(void)
{
	union Text_props text = { { 1 ,12, 0, 0, 0, 0 } };
	char choice;

	show_text_style_us(text.us_text);


	do {
		printf("f) % -15s s) % -15s a) % -15s\n", "�۲� ����", "ũ�� ����", "������ġ ����");
		printf("b) % -15s i) % -15s u) % -15s\n", "���� ���", "���ڸ� ���", "���� ���");
		printf("q) % -15s \n", "����");
		printf("�Է� : ");

		while ((choice = tolower(get_first())) != 'f' && choice != 's' && choice != 'a' && choice != 'b' && choice != 'i' && choice != 'u' && choice != 'q')
		{
			puts("��ȿ�� ������ �ƴմϴ�.");
			printf("�ٽ� �Է� : ");
		}

		switch (choice)
		{
		case 'f':
			text.us_text = change_ID_us(text.us_text);
			break;
		case 's':
			change_size_us(text.us_text);
			break;
		case 'a':
			change_align_us(text.us_text);
			break;
		case 'b':
			toggle_opt(text.us_text, 17);
			break;
		case 'i':
			toggle_opt(text.us_text, 18);
			break;
		case 'u':
			toggle_opt(text.us_text, 19);
			break;
		case 'q':
			break;
		}

		if (choice != 'q')
			show_text_style_us(text.us_text);

	} while (choice != 'q');



	return 0;
}

void show_text_style_us(unsigned long ptext)
{
	putchar('\n');
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "ũ��", "������ġ", "B", "I", "U");
	printf("%-10d %-10d %-10s %-10s %-10s %-10s\n", ptext, (ptext >> 8), align[(ptext >> 15)], On_and_Off[(ptext >> 17)], On_and_Off[(ptext >> 18)], On_and_Off[(ptext >> 19)]);
	putchar('\n');
}

long change_ID_us(unsigned long ptext)
{
	long input;

	printf("�۲� ���� (0 ~ 255) : ");
	while (scan_num("%ld", &input) != 1 || input > 255 || input < 0)
	{
		puts("��ȿ�� ���� �ƴմϴ�.");
		printf("�۲� ���� (0 ~ 255) : ");
	}

	return input;
}

void change_size_us(unsigned long ptext)
{
	long input;

	printf("ũ�� ���� (0 ~ 127) : ");
	while (scan_num("ld", &input) != 1 || input > 127 || input < 0)
	{
		printf("%ld", input);
		puts("��ȿ�� ���� �ƴմϴ�.");
		printf("ũ�� ���� (0 ~ 127) : ");
	}

	ptext >>= 8;
	ptext = input;
}

void change_align_us(unsigned long ptext)
{
	char choice;

	printf("l) %-10s c) %-10s r) %-10s\n", "����", "���", "������");
	printf("������ġ ��� : ");
	while ((choice = tolower(get_first())) != 'l' && choice != 'c' && choice != 'r')
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("l) %-10s c) %-10s r) %-10s\n", "����", "���", "������");
		printf("������ġ ��� : ");
	}

	ptext >>= 15;

	switch (choice)
	{
	case 'l':
		ptext = 0;
		break;
	case 'c':
		ptext = 1;
		break;
	case 'r':
		ptext = 2;
		break;
	}
}

void toggle_opt(unsigned long ptext, int offset)
{
	ptext >>= offset;
	ptext = ptext == 0 ? 1 : 0;
}