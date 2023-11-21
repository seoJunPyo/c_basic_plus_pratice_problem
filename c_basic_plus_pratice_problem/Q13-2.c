#include "Q13.h"

int Q13_2(int argc, char * argv[])
{
	FILE* source, * target;
	char buffer[256];
	memset(buffer, '\0', 256);
	

	if (argc < 3)
	{
		printf("���� : %s source_file target_file", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&source, argv[1], "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&target, argv[2], "w") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	printf("%s ������ %s���Ͽ� �����մϴ�.\n", argv[1], argv[2]);
	while (fread(buffer, sizeof(char), 256, source) > 0)
		fwrite(buffer, sizeof(char), 256, target);

	printf("���� �Ϸ�!\n");

	fclose(source);
	fclose(target);

	return 0;
}