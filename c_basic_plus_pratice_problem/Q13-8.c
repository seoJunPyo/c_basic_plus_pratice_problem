#include "Q13.h"

int Q13_8(int argc, char* argv[])
{
	int count, ch;
	char f_name[256] = { 0 };
	FILE* fp;

	if (argc <= 1)
	{
		printf("사용법 : %s char filename", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (argc == 2)
	{
		printf("읽을 파일 명 입력 (빈 라인 입력 시 종료) : ");
		while (gets_s(f_name, 256) != NULL && f_name[0] != '\0')
		{
			while (getchar() != '\n')
				continue;

			if (fopen_s(&fp, f_name, "r") != 0)
			{
				printf("%s 파일을 열 수 없습니다.\n", f_name);
				printf("다음 읽을 파일 명 입력 (빈 라인 입력 시 종료)  : ");
				continue;
			}

			count = 0;
			while ((ch = getc(fp)) != EOF)
				if (ch == argv[1][0])
					count++;

			fclose(fp);
			printf("%s 파일에서 \"%c\" 문자가 등장한 횟수 : %d\n", f_name, argv[1][0], count);
			printf("다음 읽을 파일 명 입력 : ");
		}
	}
	else
	{
		for (int i = 2, count = 0; i < argc; i++)
		{
			if (fopen_s(&fp, argv[i], "r") != 0)
			{
				printf("%s 파일을 열 수 없습니다.\n", argv[i]);
				continue;
			}

			while (ch = getc(fp) != EOF)
				if (ch == argv[1][0])
					count++;

			fclose(fp);
			printf("%s 파일에서 \"%c\" 문자가 등장한 횟수 : %d\n", argv[i], argv[1][0], count);
		}
	}

	printf("종료!\n");

	return 0;
}