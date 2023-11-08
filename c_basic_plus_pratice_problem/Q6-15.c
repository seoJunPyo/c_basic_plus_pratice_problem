#include <stdio.h>
#include <string.h>
#define SIZE 256

void reverse(char* str);

int Q6_15(void)
{
	char str[SIZE];

	printf("뒤집을 문자열 입력");
	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%c", &str[i], 1);
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}

	reverse(str);
	printf("%s\n", str);

	return 0;
}

static void reverse(char* str)
{
	int len = (int)strlen(str);
	char temp;

	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}