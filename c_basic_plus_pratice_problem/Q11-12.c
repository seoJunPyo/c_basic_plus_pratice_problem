#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Char_Type_Count
{
	int Upper;
	int Lower;
	int Punct;
	int Digit;
	int Word;
};

int Q11_12(void)
{
	FILE* fp;
	char f_name[256] = { 0 };
	char ch;
	struct Char_Type_Count Count = { 0, 0, 0, 0, 0 };
	
	printf("파일 명 입력 : ");
	scanf_s("%s", f_name, 256);
	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.", f_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (isspace(ch))
			Count.Word++;
		if (isupper(ch))
			Count.Upper++;
		if (islower(ch))
			Count.Lower++;
		if (ispunct(ch))
			Count.Punct++;
		if (isdigit(ch))
			Count.Digit++;
	}

	printf("단어 수 : %d\n", Count.Word);
	printf("대문자 수 : %d\n", Count.Upper);
	printf("소문자 수 : %d\n", Count.Lower);
	printf("구두점 수 : %d\n", Count.Punct);
	printf("숫자 수 : %d\n", Count.Digit);

	return 0;
}