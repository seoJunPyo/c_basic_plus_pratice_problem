#include <stdio.h>
#include <string.h>
#include "util.h"
#define SIZE 256

int Q6_7(void)
{
	char str[SIZE] = { 0 };
	char temp;
	int len;

	printf("뒤집을 단어 입력 : ");
	scanf_s("%s", str, SIZE);
	eat_chars();

	len = (int)strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	printf("뒤집힌 단어 : %s\n", str);

	return 0;
}