#include <stdio.h>
#include "util.h"

int Q6_5(void)
{
	char ch;
	int i, j, k;
	
	printf("�빮�� �Է� : ");
	while ((ch = getchar()) > 'Z' || ch < 'A')
	{
		printf("�������� ��� �����Դϴ�.\n");
		printf("�ٽ� �Է� :");
		eat_chars();
	}

	for (i = 'A'; i <= ch; i++)
	{
		for (j = 0; j < (ch - i); j++)
			printf(" ");
		for (j = 'A'; j < i; j++)
			printf("%c", j);
		for (k = j; j >= 'A'; j--)
			printf("%c", j);

		printf("\n");
	}
	
	return 0;
}