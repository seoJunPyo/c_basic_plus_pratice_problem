#include <stdio.h>
#include "util.h"

void print_char_pos(char ch, int i, int j);

int Q9_3(void)
{
	char ch;
	int i, j;

	printf("���� �Է� : ");
	ch = get_first();

	printf("�� ���� �Է� : ");
	while (scanf_s("%d %d", &i, &j) != 2)
		printf("���� �Է� : ");

	print_char_pos(ch, i, j);

	return 0;
}

void print_char_pos(char ch, int i, int j)
{
	for (int k = 0; k < i; k++)
		printf("\n");

	for (int k = 0; k < j; k++)
		printf(" ");

	printf("%c", ch);
}