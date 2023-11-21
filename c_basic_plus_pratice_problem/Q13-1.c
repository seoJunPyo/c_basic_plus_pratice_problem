#include "Q13.h"

int Q13_1(void)
{
	int ch;
	FILE* fp;
	char f_name[256] = { 0 };
	unsigned long count = 0;

	printf("파일 명 입력 : ");
	scanf_s("%s", f_name, 256);

	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 업습니다.\n", f_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}

	fclose(fp);
	printf("%s 파일에는 %ld개의 문자가 있습니다.\n", f_name, count);

	return 0;
}