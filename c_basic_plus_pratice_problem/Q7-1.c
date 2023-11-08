#include <stdio.h>

int Q7_1(void)
{
	char ch;
	int space_count = 0, line_count = 0, ch_count = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			space_count++;
		else if (ch == '\n')
			line_count++;
		else {
			ch_count++;
		}
	}

	printf("공백 : %d\n개행 : %d\n문자 : %d\n", space_count, line_count, ch_count);

	return 0;
}