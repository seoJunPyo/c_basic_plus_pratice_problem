#include "Q13.h"

int Q13_3(void)
{
	FILE* source, * target;
	char source_f_name[256] = { 0 }, target_f_name[256] = { 0 };
	int ch;


	printf("������ ���� �� �Է� : ");
	scanf_s("%s", source_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&source, source_f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", source_f_name);
		exit(EXIT_FAILURE);
	}

	printf("�ٿ����� ���� �� �Է� : ");
	scanf_s("%s", target_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&target, target_f_name, "w") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", target_f_name);
		exit(EXIT_FAILURE);
	}

	printf("%s ������ %s���Ͽ� �����մϴ�.\n", source_f_name, target_f_name);
	while ((ch = fgetc(source)) != EOF)
		fputc(toupper(ch), target);

	printf("���� �Ϸ�!\n");

	fclose(source);
	fclose(target);

	return 0;
}