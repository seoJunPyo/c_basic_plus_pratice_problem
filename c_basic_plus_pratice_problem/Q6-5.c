#include <stdio.h>
#include "util.h"

int Q6_5(void)
{
	char ch;
	int i, j, k;
	
	printf("대문자 입력 : ");
	while ((ch = getchar()) > 'Z' || ch < 'A')
	{
		printf("범위에서 벗어난 문자입니다.\n");
		printf("다시 입력 :");
		eat_chars();
	}

	for (i = 'A'; i <= ch; i++)
	{
		for (j = 0; j < (ch - i); j++)
			printf(" ");
		for (j = 'A'; j < i; j++)
			printf("%c", j);
		for (k = j; j >= 'A'; j--)
			printf("%c", j);

		printf("\n");
	}
	
	return 0;
}