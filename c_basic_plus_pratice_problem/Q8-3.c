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

	printf("파일 명 입력 : ");
	scanf_s("%s", fname, SIZE);
	eat_chars();

	if (fopen_s(&fp, fname, "r") != 0)
	{
		fprintf(stderr, "%s 파일을 열 수 없습니다.", fname);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (islower(ch))
			lower_count++;
		if (isupper(ch))
			upper_count++;
	}

	printf("소문자 갯수 : %d, 대문자 갯수 : %d\n", lower_count, upper_count);

	return 0;
}