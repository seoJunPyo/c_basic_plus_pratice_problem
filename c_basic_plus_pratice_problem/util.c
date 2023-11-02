#include <stdio.h>
#include <string.h>

char* s_gets(char* str, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void eat_chars(void)
{
	while (getchar() != '\n')
		continue;
}

char get_first(void)
{
	eat_chars();

	char ch;
	ch = getchar();

	eat_chars();

	return ch;
}
