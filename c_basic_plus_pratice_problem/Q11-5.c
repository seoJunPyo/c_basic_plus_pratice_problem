#include <stdio.h>
#include <ctype.h>
#include "util.h"

char* find_char(char* str, char ch);

int Q11_5(void)
{
	char string[256];
	char ch;
	char* ptr;

	printf("���ڿ� �Է� : ");
	fgets(string, 256, stdin);

	printf("ã�� ���� �Է� (�������� #) : ");
	while ((ch = getchar()) != '#')
	{
		ptr = find_char(string, ch);
		printf("�˻� ��� : %s\n", ptr);
		printf("ã�� ���� �Է� (�������� #) : ");
		eat_chars();
	}

	printf("����!\n");

	return 0;
}
	
	

static char* find_char(char* str, char ch)
{
	char* ptr = NULL;
	
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ch)
		{
			ptr = str + i;
			break;
		}

	return ptr;
}