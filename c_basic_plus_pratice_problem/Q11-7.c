#include <stdio.h>
#include <string.h>
#include "util.h"

char* mystrnpy(char* s1, char* s2, int n);

int Q11_7(void)
{
	char s1[256], s2[256];
	int max_len;

	printf("문자열 입력 (# 입력시 종료): ");
	gets_s(s2, 256);
	while (s2[0] != '#')
	{
		printf("최대 복사 길이 : ");
		while (scanf_s("%d", &max_len) != 1)
		{
			printf("유효한 숫자가 아닙니다.\n");
			printf("다시 입력 : ");
			eat_chars();
		}
		eat_chars();

		mystrnpy(s1, s2, max_len);

		printf("s1 : %s, s2 : %s\n", s1, s2);

		printf("문자열 입력 (# 입력시 종료): ");
		gets_s(s2, 256);
	}

	printf("종료!\n");

	return 0;
}

char* mystrnpy(char* s1, char* s2, int n)
{
	int idx;
	int len = strlen(s2) > n ? n : strlen(s2);

	for (idx = 0; idx < len; idx++)
		s1[idx] = s2[idx];
	s1[len] = '\0';
	
	return s1;
}