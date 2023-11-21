#include "Q13.h"

int Q13_11(int argc, char * argv[])
{
	FILE* fp;
	char line[256];

	if (argc < 3)
	{
		printf("���� : %s string filename", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&fp, argv[2], "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", argv[2]);
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