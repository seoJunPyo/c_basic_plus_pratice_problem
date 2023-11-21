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
		printf("%s ������ �� �� �����ϴ�.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (int i = 2; i < argc; i++)
	{
		if (strcmp(argv[1], argv[i]) == 0)
			printf("�ڱ� �ڽſ��� ������ �� �����ϴ�.\n");
		else if (fopen_s(&fs, argv[i], "r") != 0)
			printf("%s ������ �� �� �����ϴ�.\n", argv[1]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFFERSIZE) != 0)
			{
				printf("�Է� ���۸� ������ �� �����ϴ�.\n");
				continue;
			}

			append(fs, fa);

			if (ferror(fa) != 0)
				printf("%s ������ �д� �� ������ �߻��߽��ϴ�.\n", argv[1]);

			if (ferror(fs) != 0)
				printf("%s ������ �д� �� ������ �߻��߽��ϴ�.\n", argv[i]);

			fclose(fs);
			files++;
			printf("%s ������ ������ ���ٿ����ϴ�.\n", argv[i]);
		}
	}

	printf("����. �� %d���� ������ ���ٿ����ϴ�.\n", files);
	rewind(fa);
	printf("%s ���� \n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	printf("���� ���� ����.\n");
	fclose(fa);

	return 0;
}

static void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFFERSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFFERSIZE, source)) > 0)
	{
		printf("���� :  %s\n", temp);
		fwrite(temp, sizeof(char), bytes, dest);
	}
}