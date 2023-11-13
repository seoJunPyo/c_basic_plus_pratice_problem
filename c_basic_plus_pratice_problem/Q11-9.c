#include <stdio.h>
#include <string.h>

void reverse(char* str);

int Q11_9(void)
{
	char str[256];

	printf("뒤집을 문자열 입력 (종료하려면 빈 라인) : ");
	gets_s(str, 256);

	while (str[0] != '\0')
	{
		reverse(str);
		printf("뒤집은 문자열 : %s\n", str);

		printf("뒤집을 문자열 입력 (종료하려면 빈 라인) : ");
		gets_s(str, 256);
	}

	printf("종료!\n");

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
