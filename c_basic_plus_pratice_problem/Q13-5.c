#include "Q13.h"
#define BUFFERSIZE 4096

void append(FILE* source, FILE* dest);

int Q13_5(int argc, char * argv[])
{
	FILE* fa, * fs;
	int files = 0;
	int ch;

	if (fopen_s(&fa, argv[1], "a+") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (int i = 2; i < argc; i++)
	{
		if (strcmp(argv[1], argv[i]) == 0)
			printf("자기 자신에게 덧붙일 수 없습니다.\n");
		else if (fopen_s(&fs, argv[i], "r") != 0)
			printf("%s 파일을 열 수 없습니다.\n", argv[1]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFFERSIZE) != 0)
			{
				printf("입력 버퍼를 생성할 수 없습니다.\n");
				continue;
			}

			append(fs, fa);

			if (ferror(fa) != 0)
				printf("%s 파일을 읽는 데 에러가 발생했습니다.\n", argv[1]);

			if (ferror(fs) != 0)
				printf("%s 파일을 읽는 데 에러가 발생했습니다.\n", argv[i]);

			fclose(fs);
			files++;
			printf("%s 파일의 내용을 덧붙였습니다.\n", argv[i]);
		}
	}

	printf("종료. 총 %d개의 파일을 덧붙였습니다.\n", files);
	rewind(fa);
	printf("%s 내용 \n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	printf("파일 내용 종료.\n");
	fclose(fa);

	return 0;
}

static void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFFERSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFFERSIZE, source)) > 0)
	{
		printf("문장 :  %s\n", temp);
		fwrite(temp, sizeof(char), bytes, dest);
	}
}