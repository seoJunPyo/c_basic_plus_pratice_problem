#include "Q13.h"

int Q13_4(int argc, char *argv[])
{
	FILE* fp;
	int ch;

	if (argc == 1)
	{
		printf("사용법 : %s ...filenames\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		if (fopen_s(&fp, argv[i], "r") == 0)
		{
			printf("%s 파일 내용 : \n", argv[i]);
			while ((ch = fgetc(fp)) != EOF)
				putchar(ch);

			fclose(fp);
		}
		else
			printf("%s 파일을 여는데 실패했습니다.\n", argv[i]);

		printf("--------------------------------------------------------\n");
	}

	return 0;
}