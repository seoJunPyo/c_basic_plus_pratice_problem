#include <stdio.h>
#include <ctype.h>
#include "util.h"

void scan_string_to_n(char string[], int n);

int Q11_2(void)
{
	char string[256];
	scan_string_to_n(string, 10);

	printf("%s", string);

	return 0;
}

static void scan_string_to_n(char string[], int n)
{
	char ch;
	int i;

	for (i = 0; i < n; i++)
	{
		if (isspace(ch = getchar()))
			break;

		string[i] = ch;
	}
		
	string[i] = '\0';

	eat_chars();
}