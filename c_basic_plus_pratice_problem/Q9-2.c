#include <stdio.h>
#include "util.h"

void print_char_col(char ch, int i, int j);

int Q9_2(void)
{
	char ch;
	int i, j;

	printf("���� �Է� : ");
	ch = get_first();

	printf("�� ���� �Է� : ");
	while (scanf_s("%d %d", &i, &j) != 2)
		printf("���� �Է� : ");

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