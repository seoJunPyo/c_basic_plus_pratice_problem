#include <stdio.h>
#include <ctype.h>
#include "util.h"

void scan_word(char word[], int max_count);

int Q11_4(void)
{
	char word[256];
	scan_word(word, 2);

	printf("%s", word);

	return 0;
}

static void scan_word(char word[], int max_count)
{
	int count = 0;
	char ch;

	while (isspace(ch = getchar()))
		continue;

	do {
		word[count++] = ch;
	} while (!isspace(ch = getchar()) && count < max_count);

	word[count] = '\0';
	eat_chars();
}