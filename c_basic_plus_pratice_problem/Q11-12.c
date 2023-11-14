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
	
	printf("���� �� �Է� : ");
	scanf_s("%s", f_name, 256);
	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.", f_name);
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

	printf("�ܾ� �� : %d\n", Count.Word);
	printf("�빮�� �� : %d\n", Count.Upper);
	printf("�ҹ��� �� : %d\n", Count.Lower);
	printf("������ �� : %d\n", Count.Punct);
	printf("���� �� : %d\n", Count.Digit);

	return 0;
}