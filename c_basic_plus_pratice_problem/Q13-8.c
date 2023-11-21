#include "Q13.h"

int Q13_8(int argc, char* argv[])
{
	int count, ch;
	char f_name[256] = { 0 };
	FILE* fp;

	if (argc <= 1)
	{
		printf("���� : %s char filename", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (argc == 2)
	{
		printf("���� ���� �� �Է� (�� ���� �Է� �� ����) : ");
		while (gets_s(f_name, 256) != NULL && f_name[0] != '\0')
		{
			while (getchar() != '\n')
				continue;

			if (fopen_s(&fp, f_name, "r") != 0)
			{
				printf("%s ������ �� �� �����ϴ�.\n", f_name);
				printf("���� ���� ���� �� �Է� (�� ���� �Է� �� ����)  : ");
				continue;
			}

			count = 0;
			while ((ch = getc(fp)) != EOF)
				if (ch == argv[1][0])
					count++;

			fclose(fp);
			printf("%s ���Ͽ��� \"%c\" ���ڰ� ������ Ƚ�� : %d\n", f_name, argv[1][0], count);
			printf("���� ���� ���� �� �Է� : ");
		}
	}
	else
	{
		for (int i = 2, count = 0; i < argc; i++)
		{
			if (fopen_s(&fp, argv[i], "r") != 0)
			{
				printf("%s ������ �� �� �����ϴ�.\n", argv[i]);
				continue;
			}

			while (ch = getc(fp) != EOF)
				if (ch == argv[1][0])
					count++;

			fclose(fp);
			printf("%s ���Ͽ��� \"%c\" ���ڰ� ������ Ƚ�� : %d\n", argv[i], argv[1][0], count);
		}
	}

	printf("����!\n");

	return 0;
}