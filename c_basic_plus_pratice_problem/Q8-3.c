#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "util.h"
#define SIZE 256

int Q8_3(void)
{
	FILE* fp;
	char fname[256] = { 0 };
	char ch;
	int lower_count = 0, upper_count = 0;

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
		if (islower(ch))
			lower_count++;
		if (isupper(ch))
			upper_count++;
	}

	printf("�ҹ��� ���� : %d, �빮�� ���� : %d\n", lower_count, upper_count);

	return 0;
}