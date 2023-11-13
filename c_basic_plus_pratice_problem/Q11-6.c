#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "util.h"

int is_within(char ch, char* str);

int Q11_6(void)
{
	char string[256];
	char ch;

	printf("���ڿ� �Է� : ");
	gets_s(string, 256);

	printf("ã�� ���� �Է� (�������� #) : ");
	while ((ch = getchar()) != '#')
	{
		if (is_within(ch, string))
			printf("ã�� ���� %c�� ���ڿ� %s�� �����մϴ�.\n", ch, string);
		else
			printf("ã�� ���� %c�� ���ڿ� %s�� �������� �ʽ��ϴ�.\n", ch, string);

		printf("ã�� ���� �Է� (�������� #) : ");
		eat_chars();
	}

	printf("����!\n");

	return 0;
}

static int is_within(char ch, char* str)
{
	int is_in = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ch)
		{
			is_in = 1;
			break;
		}
	}

	return is_in;
}