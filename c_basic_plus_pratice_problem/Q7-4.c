#include <stdio.h>

int Q7_4(void)
{
	char ch;
	int count = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{
			printf("!");
			count++;
		}
		else if (ch == '!')
		{
			printf("!!");
			count++;
		}
		else
			printf("%c", ch);
	}

	printf("���ڸ� ��ü�� Ƚ�� : %d\n", count);

	return 0;
}