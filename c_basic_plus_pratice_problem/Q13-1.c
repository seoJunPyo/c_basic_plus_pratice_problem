#include "Q13.h"

int Q13_1(void)
{
	int ch;
	FILE* fp;
	char f_name[256] = { 0 };
	unsigned long count = 0;

	printf("���� �� �Է� : ");
	scanf_s("%s", f_name, 256);

	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", f_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}

	fclose(fp);
	printf("%s ���Ͽ��� %ld���� ���ڰ� �ֽ��ϴ�.\n", f_name, count);

	return 0;
}