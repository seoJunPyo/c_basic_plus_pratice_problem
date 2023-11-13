#include <stdio.h>
#include <string.h>

char* string_in(char* source, char* sub);

int Q11_8(void)
{
	char s1[256], s2[256];
	char* ptr;
	
	printf("문자열 입력 (종료하려면 빈 라인) : ");
	gets_s(s1, 256);

	while (s1[0] != '\0')
	{
		printf("검색 문자열 입력 : ");
		gets_s(s2, 256);

		ptr = string_in(s1, s2);

		if (ptr != NULL)
			printf("검색 결과 : %s\n", ptr);
		else
			printf("검색 결과가 없습니다.\n");

		printf("문자열 입력 (종료하려면 빈 라인) : ");
		gets_s(s1, 256);
	}

	printf("종료!\n");

	return 0;
}

char* string_in(char* source, char* sub)
{
	char* ptr = NULL;
	int source_len = (int)strlen(source);
	int sub_len = (int)strlen(sub);

	for (int i = 0; i < source_len; i++)
	{
		if (source[i] == sub[0])
		{
			int is_in = 1;

			for (int j = 0; j < sub_len; j++)
				if (source[i + j] != sub[j] || source[i + j] == '\0')
				{
					is_in = 0;
					break;
				}

			if (is_in == 1)
				ptr = source + i;
		}

		if (ptr != NULL)
			break;
	}

	return ptr;
}