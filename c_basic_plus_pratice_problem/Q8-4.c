#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "util.h"
#define SIZE 256

int Q8_4(void)
{
	FILE* fp;
	char fname[256] = { 0 };
	char ch;
	int char_count = 0, word_count = 0;

	printf("���� �� �Է� : ");
	scanf_s("%s", fname, SIZE);
	eat_chars();

	if (fopen_s(&fp, fname, "r") != 0)
	{
		fprintf(stderr, "%s ������ �� �� �����ϴ�.", fname);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (isspace(ch))
			word_count++;
		else if (ispunct(ch))
			continue;
		else
			char_count++;

	}

	printf("�ܾ�� ���� ��� ���� �� : %.2f", (double)word_count / char_count);

	return 0;
}