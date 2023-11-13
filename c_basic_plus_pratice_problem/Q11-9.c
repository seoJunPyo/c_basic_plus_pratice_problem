#include <stdio.h>
#include <string.h>

void reverse(char* str);

int Q11_9(void)
{
	char str[256];

	printf("������ ���ڿ� �Է� (�����Ϸ��� �� ����) : ");
	gets_s(str, 256);

	while (str[0] != '\0')
	{
		reverse(str);
		printf("������ ���ڿ� : %s\n", str);

		printf("������ ���ڿ� �Է� (�����Ϸ��� �� ����) : ");
		gets_s(str, 256);
	}

	printf("����!\n");

	return 0;
}

static void reverse(char* str)
{
	int len = (int)strlen(str);
	char temp;

	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}
