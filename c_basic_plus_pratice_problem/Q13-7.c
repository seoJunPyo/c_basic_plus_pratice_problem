#include "Q13.h"

int Q13_7(void)
{
	FILE* fp1, * fp2;
	char first_f_name[256] = { 0 }, second_f_name[256] = { 0 };
	char line_1[256], line_2[256];
	char* status_1, * status_2;

	printf("���� ù ��° ���� �� : ");
	scanf_s("%s", first_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&fp1, first_f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", first_f_name);
		exit(EXIT_FAILURE);
	}

	printf("���� �� ��° ���� �� : ");
	scanf_s("%s", second_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&fp2, second_f_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", second_f_name);
		exit(EXIT_FAILURE);
	}

	// a.
	while (1)
	{
		status_1 = fgets(line_1, 256, fp1);
		if (status_1 != NULL)
		{
			line_1[strlen(line_1) - 1] = '\0';
			printf("%s\n", line_1);
		}

		status_2 = fgets(line_2, 256, fp2);
		if (status_2 != NULL)
		{
			line_2[strlen(line_2) - 1] = '\0';
			printf("%s\n", line_2);
		}

		if (status_1 == NULL && status_2 == NULL)
			break;
	}

	rewind(fp1);
	rewind(fp2);

	// b.
	printf("���� ������ �ϳ��� �������� ��� : \n");
	while (1)
	{
		status_1 = fgets(line_1, 256, fp1);
		if (status_1 != NULL)
		{
			line_1[strlen(line_1) - 1] = '\0';
			printf("%s ", line_1);
		}

		status_2 = fgets(line_2, 256, fp2);
		if (status_2 != NULL)
		{
			line_2[strlen(line_2) - 1] = '\0';
			printf("%s\n", line_2);
		}

		if (status_1 == NULL && status_2 == NULL)
			break;
	}

	printf("����!\n");

	return 0;
}