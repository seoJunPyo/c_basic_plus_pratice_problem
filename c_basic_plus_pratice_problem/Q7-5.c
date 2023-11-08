#include <stdio.h>

int Q7_5(void)
{
	char ch;
	int count = 0;

	while ((ch =getchar()) != '#')
	{
		switch (ch)
		{
		case '.':
			printf("!");
			count++;
			break;
		case '!':
			printf("!!");
			count++;
			break;
		default:
			printf("%c", ch);
			break;
		}
	}

	printf("문자를 대체한 횟수 : %d\n", count);

	return 0;
}