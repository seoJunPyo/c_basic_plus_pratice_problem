#include "Q13.h"

int Q13_3(void)
{
	FILE* source, * target;
	char source_f_name[256] = { 0 }, target_f_name[256] = { 0 };
	int ch;


	printf("복사할 파일 명 입력 : ");
	scanf_s("%s", source_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&source, source_f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 업습니다.\n", source_f_name);
		exit(EXIT_FAILURE);
	}

	printf("붙여넣을 파일 명 입력 : ");
	scanf_s("%s", target_f_name, 256);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&target, target_f_name, "w") != 0)
	{
		printf("%s 파일을 열 수 업습니다.\n", target_f_name);
		exit(EXIT_FAILURE);
	}

	printf("%s 파일을 %s파일에 복사합니다.\n", source_f_name, target_f_name);
	while ((ch = fgetc(source)) != EOF)
		fputc(toupper(ch), target);

	printf("복사 완료!\n");

	fclose(source);
	fclose(target);

	return 0;
}