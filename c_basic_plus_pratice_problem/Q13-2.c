#include "Q13.h"

int Q13_2(int argc, char * argv[])
{
	FILE* source, * target;
	char buffer[256];
	memset(buffer, '\0', 256);
	

	if (argc < 3)
	{
		printf("사용법 : %s source_file target_file", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&source, argv[1], "r") != 0)
	{
		printf("%s 파일을 열 수 업습니다.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fopen_s(&target, argv[2], "w") != 0)
	{
		printf("%s 파일을 열 수 업습니다.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	printf("%s 파일을 %s파일에 복사합니다.\n", argv[1], argv[2]);
	while (fread(buffer, sizeof(char), 256, source) > 0)
		fwrite(buffer, sizeof(char), 256, target);

	printf("복사 완료!\n");

	fclose(source);
	fclose(target);

	return 0;
}