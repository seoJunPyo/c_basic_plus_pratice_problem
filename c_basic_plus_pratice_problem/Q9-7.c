#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 256

int get_alpabets_order(char ch);

int Q9_7(void)
{
	FILE* fp;
	char file_name[SIZE] = { 0 };
	char ch;
	int order;
	
	printf("���� �� �Է� : ");
	scanf_s("%s", file_name, SIZE);
	if (fopen_s(&fp, file_name, "r") != 0)
	{
		printf("%s ������ �� �� �����ϴ�.\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
		if ((order = get_alpabets_order(ch)) != -1)
			printf("%c�� %d��° ���ĺ��Դϴ�.", ch, order);

	return 0;
}

int get_alpabets_order(char ch)
{
	int order;

	if (islower(ch))
		order = ch - 'a';
	else if (isupper(ch))
		order = ch - 'A';
	else
		order = -1;

	return order;
}