#include "Q13.h"

int Q13_11(int argc, char * argv[])
{
	FILE* fp;
	char line[256];

	if (argc < 3)
	{
		printf("사용법 : %s string filename", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&fp, argv[2], "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 256, fp) != NULL)
	{
		if (strstr(line, argv[1]) != NULL)
			puts(line);
	}

	fclose(fp);

	return 0;
}