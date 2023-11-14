#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Q11_16(int argc, char* argv[])
{
	FILE* fp = NULL;
	char f_name[256] = { 0 };
	char ch;

	printf("���� �� �Է� : ");
	scanf_s("%s", f_name, 256);
	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", f_name);
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
			printf("��ȿ�� �������ڰ� �ƴմϴ�.\n");
			break;
		}
	}

	return 0;
}