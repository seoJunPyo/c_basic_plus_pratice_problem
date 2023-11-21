#include "Q13.h"

int Q13_10(void)
{
	FILE* fp;
	char f_name[256];
	int ch;
	long pos;

	printf("���� �� �Է� : ");
	gets_s(f_name, 256);

	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", f_name);
		exit(EXIT_FAILURE);
	}

	printf("���Ͽ��� �б� ������ ��ġ �Է� : ");
	while (scanf_s("%ld", &pos) == 1 && pos > 0)
	{
		fseek(fp, pos, SEEK_SET);

		while ((ch = getc(fp)) != EOF)
			putchar(ch);

		printf("\n");
		printf("���Ͽ��� �б� ������ ��ġ �Է� : ");
	}

	fclose(fp);

	printf("����!\n");

	return 0;
}