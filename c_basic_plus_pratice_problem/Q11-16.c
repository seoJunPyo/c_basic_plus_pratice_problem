#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Q11_16(int argc, char* argv[])
{
	FILE* fp = NULL;
	char f_name[256] = { 0 };
	char ch;

	printf("파일 명 입력 : ");
	scanf_s("%s", f_name, 256);
	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", f_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (argv[1] == NULL || argv[1][1] == 'p')
			printf("%c", ch);

		else if (argv[1][1] == 'u')
			printf("%c", toupper(ch));

		else if (argv[1][1] == 'l')
			printf("%c", tolower(ch));

		else
		{
			printf("유효한 전달인자가 아닙니다.\n");
			break;
		}
	}

	return 0;
}