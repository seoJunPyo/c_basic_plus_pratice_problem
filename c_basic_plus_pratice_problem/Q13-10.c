#include "Q13.h"

int Q13_10(void)
{
	FILE* fp;
	char f_name[256];
	int ch;
	long pos;

	printf("파일 명 입력 : ");
	gets_s(f_name, 256);

	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", f_name);
		exit(EXIT_FAILURE);
	}

	printf("파일에서 읽기 시작할 위치 입력 : ");
	while (scanf_s("%ld", &pos) == 1 && pos > 0)
	{
		fseek(fp, pos, SEEK_SET);

		while ((ch = getc(fp)) != EOF)
			putchar(ch);

		printf("\n");
		printf("파일에서 읽기 시작할 위치 입력 : ");
	}

	fclose(fp);

	printf("종료!\n");

	return 0;
}