#include <stdio.h>
#include <ctype.h>

char get_first(void);

int Q8_6(void)
{
	char ch;
	ch = get_first();

	printf("%c", ch);
	return 0;
}

static char get_first(void)
{
	char ch;

	while (isspace(ch = getchar()))
		continue;

	while (getchar() != '\n')
		continue;

	return ch;
}