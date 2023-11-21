#include "Q13.h"

static char signals[10] = { ' ', '`', ',', '.', '~', '-', '=', '+', '*', '#' };

int Q13_13(void)
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
		for (int j = 0; j < 30; j++)
			fscanf_s(fp, "%d", &nums[i][j]);
	
	if (abs(nums[0][0] - nums[0][1]) >= 1 || abs(nums[0][0] - nums[1][0]) >= 1)
		nums[0][0] = (nums[0][1] + nums[1][0]) / 2;

	if (abs(nums[0][29] - nums[0][28]) >= 1 || abs(nums[0][29] - nums[1][29]) >= 1)
		nums[0][29] = (nums[0][28] + nums[1][29]) / 2;

	if (abs(nums[19][0] - nums[18][0]) >= 1 || abs(nums[19][0] - nums[19][1]) >= 1)
		nums[19][0] = (nums[18][0] + nums[19][1]) / 2;

	if (abs(nums[19][29] - nums[18][29]) >= 1 || abs(nums[19][29] - nums[19][28]) >= 1)
		nums[19][29] = (nums[18][29] + nums[19][29]) / 2;

	for (int i = 1; i < 19; i++)
	{
		int middle_left = nums[i][0];
		int middle_right = nums[i][29];

		if (abs(nums[i][0] - nums[i - 1][0]) >= 1 || abs(nums[i][0] - nums[i + 1][0]) >= 1 || abs(nums[i][0] - nums[i][1]) >= 1)
			nums[i][0] = (nums[i - 1][0] + nums[i + 1][0] + nums[i][1]) / 3;

		if (abs(nums[i][29] - nums[i - 1][29]) >= 1 || abs(nums[i][29] - nums[i + 1][29]) >= 1 || abs(nums[i][29] - nums[i][28]) >= 1)
			nums[i][29] = (nums[i - 1][29] + nums[i + 1][29] + nums[i][28]) / 3;
	}

	for (int j = 1; j < 29; j++)
	{
		int middle_left = nums[0][j];
		int middle_right = nums[19][j];

		if (abs(nums[0][j] - nums[0][j + 1]) >= 1 || abs(nums[0][j] - nums[0][j - 1]) >= 1 || abs(nums[0][j] - nums[1][j]) >= 1)
			nums[0][j] = (nums[0][j + 1] + nums[0][j - 1] + nums[1][j]) / 3;

		if (abs(nums[19][j] - nums[19][j + 1]) >= 1 || abs(nums[19][j] - nums[19][j - 1]) >= 1 || abs(nums[19][j] - nums[18][j]) >= 1)
			nums[19][j] = (nums[19][j + 1] + nums[19][j - 1] + nums[18][j]) / 3;
	}


	for (int i = 1; i < 19; i++)
		for (int j = 1; j < 29; j++)
		{
			int middle = nums[i][j];
			int top = nums[i][j + 1];
			int bottm = nums[i][j - 1];
			int right = nums[i + 1][j];
			int left = nums[i - 1][j];

			if (abs(middle - top) >= 1 || abs(middle - bottm) >= 1 || abs(middle - right) >= 1 || abs(middle - left) >= 1)
				nums[i][j] = (top + bottm + right + left) / 4;
		}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
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
