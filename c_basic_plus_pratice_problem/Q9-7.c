#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 256

int get_alpabets_order(char ch);

int Q9_7(void)
{
	FILE* fp;
	char file_name[SIZE] = { 0 };
	char ch;
	int order;
	
	printf("파일 명 입력 : ");
	scanf_s("%s", file_name, SIZE);
	if (fopen_s(&fp, file_name, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
		if ((order = get_alpabets_order(ch)) != -1)
			printf("%c는 %d번째 알파벳입니다.", ch, order);

	return 0;
}

int get_alpabets_order(char ch)
{
	int order;

	if (islower(ch))
		order = ch - 'a';
	else if (isupper(ch))
		order = ch - 'A';
	else
		order = -1;

	return order;
}