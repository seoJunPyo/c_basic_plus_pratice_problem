#include "Q13.h"

int Q13_6(void)
{
	FILE* in, * out;
	int ch, count = 0;
	char in_f_name[256] = { 0 };
	char out_f_name[256] = { 0 };

	printf("������ ���� �� �Է� : ");
	scanf_s("%s", in_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&in, in_f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", in_f_name);
		exit(EXIT_FAILURE);
	}

	printf("���� ����� ������ ���� �� �Է� : ");
	scanf_s("%s", out_f_name, 252);
	strcat_s(out_f_name, 252, ".red");
	while (getchar() != '\n')
		continue;

	if (fopen_s(&out, out_f_name, "w") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", out_f_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out))
		printf("������ �ݴµ� �����߽��ϴ�.\n");

	return 0;
}