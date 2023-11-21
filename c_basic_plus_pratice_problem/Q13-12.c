#include "Q13.h"

static char signals[10] = { ' ', '`', ',', '.', '~', '-', '=', '+', '*', '#' };

int Q13_12(void)
{
	int nums[20][30];
	char str[20][31];
	FILE* fp;
	char f_name[256];

	printf("파일 명 입력 : ");
	gets_s(f_name, 256);

	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", f_name);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			fscanf_s(fp, "%d", &nums[i][j]);
			str[i][j] = signals[nums[i][j]];
		}

		str[i][30] = '\0';
	}

	fclose(fp);
	if (fopen_s(&fp, "result.txt", "w") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", f_name);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 20; i++)
	{
		printf("%s\n", str[i]);
		fprintf(fp, "%s\n", str[i]);
	}

	fclose(fp);
	return 0;
}
