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

	printf("문자를 대체한 횟수 : %d\n", count);

	return 0;
}