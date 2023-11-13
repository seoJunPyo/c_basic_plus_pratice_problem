#include <stdio.h>
#include <string.h>
#include "util.h"

char* mystrnpy(char* s1, char* s2, int n);

int Q11_7(void)
{
	char s1[256], s2[256];
	int max_len;

	printf("���ڿ� �Է� (# �Է½� ����): ");
	gets_s(s2, 256);
	while (s2[0] != '#')
	{
		printf("�ִ� ���� ���� : ");
		while (scanf_s("%d", &max_len) != 1)
		{
			printf("��ȿ�� ���ڰ� �ƴմϴ�.\n");
			printf("�ٽ� �Է� : ");
			eat_chars();
		}
		eat_chars();

		mystrnpy(s1, s2, max_len);

		printf("s1 : %s, s2 : %s\n", s1, s2);

		printf("���ڿ� �Է� (# �Է½� ����): ");
		gets_s(s2, 256);
	}

	printf("����!\n");

	return 0;
}

char* mystrnpy(char* s1, char* s2, int n)
{
	int idx;
	int len = strlen(s2) > n ? n : strlen(s2);

	for (idx = 0; idx < len; idx++)
		s1[idx] = s2[idx];
	s1[len] = '\0';
	
	return s1;
}