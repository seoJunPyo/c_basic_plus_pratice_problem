#include <stdio.h>
#include "util.h"

void scan_string_to_n(char string[], int n);

int Q11_1(void)
{
	char string[256];
	scan_string_to_n(string, 10);

	printf("%s", string);

	return 0;
}

static void scan_string_to_n(char string[], int n)
{
	for (int i = 0; i < n; i++)
		string[i] = getchar();
	string[n] = '\0';

	eat_chars();
}