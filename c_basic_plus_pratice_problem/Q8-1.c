#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define SIZE 256

int Q8_1(void)
{
	FILE* fp;
	char fname[256] = { 0 };
	int count = 0;

	printf("���� �� �Է� : ");
	scanf_s("%s", fname, SIZE);
	eat_chars();

	if (fopen_s(&fp, fname, "r") != 0)
	{
		fprintf(stderr, "%s ������ �� �� �����ϴ�.", fname);
		exit(EXIT_FAILURE);
	}

	while (fgetc(fp) != EOF)
		count++;

	return 0;
}