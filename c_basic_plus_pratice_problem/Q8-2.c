#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define SIZE 256

int Q8_2(void)
{
	FILE* fp;
	char fname[256] = { 0 };
	char ch;
	int count = 0;

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
		switch (ch)
		{
		case '\n' :
			printf("\\n-%d ", ch);
			break;
		case '\t' :
			printf("\\t-%d ", ch);
			break;
		case '\r' :
			printf("\\r-%d ", ch);
			break;
		default:
			printf("%c-%d ", ch, ch);
			break;
		}

		if (++count % 10 == 0)
			printf("\n");
	}

	return 0;
}