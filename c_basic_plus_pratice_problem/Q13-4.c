#include "Q13.h"

int Q13_4(int argc, char *argv[])
{
	FILE* fp;
	int ch;

	if (argc == 1)
	{
		printf("���� : %s ...filenames\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		if (fopen_s(&fp, argv[i], "r") == 0)
		{
			printf("%s ���� ���� : \n", argv[i]);
			while ((ch = fgetc(fp)) != EOF)
				putchar(ch);

			fclose(fp);
		}
		else
			printf("%s ������ ���µ� �����߽��ϴ�.\n", argv[i]);

		printf("--------------------------------------------------------\n");
	}

	return 0;
}