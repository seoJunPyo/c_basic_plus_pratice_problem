#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "util.h"

int is_within(char ch, char* str);

int Q11_6(void)
{
	char string[256];
	char ch;

	printf("문자열 입력 : ");
	gets_s(string, 256);

	printf("찾을 문자 입력 (끝내려면 #) : ");
	while ((ch = getchar()) != '#')
	{
		if (is_within(ch, string))
			printf("찾는 문자 %c가 문자열 %s에 존재합니다.\n", ch, string);
		else
			printf("찾는 문자 %c가 문자열 %s에 존재하지 않습니다.\n", ch, string);

		printf("찾을 문자 입력 (끝내려면 #) : ");
		eat_chars();
	}

	printf("종료!\n");

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