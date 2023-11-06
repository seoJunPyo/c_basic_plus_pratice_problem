#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include "util.h"
#include "Q15.h"

void show_text_style(struct text_style*);
void change_ID(struct text_style* ptext);
void change_size(struct text_style* ptext);
void change_align(struct text_style* ptext);

struct text_style {
	unsigned int ID : 8;
	unsigned int size : 7;
	unsigned int align : 2;
	unsigned int bold : 1;
	unsigned int itelic : 1;
	unsigned int underline : 1;
};

char* align[3] = { "����", "���", "������" };
char* On_and_Off[2] = { "Off", "On" };

int Q15_6(void)
{
	struct text_style text = { 1 ,12, 0, 0, 0, 0 };
	char choice;

	show_text_style(&text);

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
			case 'f' :
				change_ID(&text);
				break;
			case 's':
				change_size(&text);
				break;
			case 'a' :
				change_align(&text);
				break;
			case 'b':
				text.bold = text.bold == 0 ? 1 : 0;
				break;
			case 'i':
				text.itelic = text.itelic == 0 ? 1 : 0;
				break;
			case 'u':
				text.underline = text.underline == 0 ? 1 : 0;
				break;
			case 'q':
				break;
		}

		if (choice != 'q')
			show_text_style(&text);

	} while (choice != 'q');

  
	return 0;
}

void show_text_style(struct text_style* ptext)
{
	putchar('\n');
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "ID", "ũ��", "������ġ", "B", "I", "U");
	printf("%-10d %-10d %-10s %-10s %-10s %-10s\n", ptext->ID, ptext->size, align[ptext->align], On_and_Off[ptext->bold], On_and_Off[ptext->itelic], On_and_Off[ptext->underline]);
	putchar('\n');
}

void change_ID(struct text_style* ptext)
{
	int input;

	printf("�۲� ���� (0 ~ 255) : ");
	while (scan_num("%d", &input) != 1 || input > 255 || input < 0)
	{
		puts("��ȿ�� ���� �ƴմϴ�.");
		printf("�۲� ���� (0 ~ 255) : ");
	}

	ptext->ID = input;
}

void change_size(struct text_style* ptext)
{
	int input;

	printf("ũ�� ���� (0 ~ 127) : ");
	while (scan_num("%d", &input) != 1 || input > 127 || input < 0)
	{
		puts("��ȿ�� ���� �ƴմϴ�.");
		printf("ũ�� ���� (0 ~ 127) : ");
	}

	ptext->size = input;
}

void change_align(struct text_style* ptext)
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

	switch (choice)
	{
		case 'l' :
			ptext->align = 0;
			break;
		case 'c':
			ptext->align = 1;
			break;
		case 'r':
			ptext->align = 2;
			break;
	}
}
