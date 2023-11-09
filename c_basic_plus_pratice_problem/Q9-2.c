#include <stdio.h>
#include "util.h"

void print_char_col(char ch, int i, int j);

int Q9_2(void)
{
	char ch;
	int i, j;

	printf("문자 입력 : ");
	ch = get_first();

	printf("두 수를 입력 : ");
	while (scanf_s("%d %d", &i, &j) != 2)
		printf("수를 입력 : ");

	print_char_col(ch, i, j);
	
	return 0;
}

void print_char_col(char ch, int i, int j)
{
	for (int k = 0; k <= j; k++)
	{
		if (k < i)
			printf("\n");
		else
			printf("%c\n", ch);
	}
}