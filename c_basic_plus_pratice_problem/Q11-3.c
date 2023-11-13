#include <stdio.h>
#include <ctype.h>
#include "util.h"

void scan_word(char word[]);

int Q11_3(void)
{
	char word[256];
	scan_word(word);

	printf("%s", word);

	return 0;
}

static void scan_word(char word[])
{
	int count = 0;
	char ch;

	while (isspace(ch = getchar()))
		continue;

	do {
		word[count++] = ch;
	} while (!isspace(ch = getchar()));

	word[count] = '\0';
	eat_chars();
}