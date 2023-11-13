#include <stdio.h>
#include <ctype.h>
#include "util.h"

char* find_char(char* str, char ch);

int Q11_5(void)
{
	char string[256];
	char ch;
	char* ptr;

	printf("문자열 입력 : ");
	fgets(string, 256, stdin);

	printf("찾을 문자 입력 (끝내려면 #) : ");
	while ((ch = getchar()) != '#')
	{
		ptr = find_char(string, ch);
		printf("검색 결과 : %s\n", ptr);
		printf("찾을 문자 입력 (끝내려면 #) : ");
		eat_chars();
	}

	printf("종료!\n");

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