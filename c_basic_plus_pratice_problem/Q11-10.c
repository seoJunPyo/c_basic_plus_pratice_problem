#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_space(char* str, int size);

int Q11_10(void)
{
	char str[256];

	printf("������ ������ ���ڿ� �Է� (�����Ϸ��� �� ����) : ");
	gets_s(str, 256);

	while (str[0] != '\0')
	{
		remove_space(str, 256);
		printf("������ ������ ���ڿ� : %s\n", str);

		printf("������ ������ ���ڿ� �Է� (�����Ϸ��� �� ����) : ");
		gets_s(str, 256);
	}

	return 0;
}

static void remove_space(char* str, int size)
{
	char* result_string = (char*)malloc(sizeof(char) * size);
	char* ptr = str;
	int count = 0;

	if (result_string == NULL)
	{
		printf("�޸� ������ �����մϴ�.\n");
		return;
	}

	while (*ptr != '\0' )
	{
		if (*ptr != ' ')
			result_string[count++] = *ptr;
		ptr++;
	}
	result_string[count] = '\0'; 

	strncpy_s(str, 256, result_string, 256);
}