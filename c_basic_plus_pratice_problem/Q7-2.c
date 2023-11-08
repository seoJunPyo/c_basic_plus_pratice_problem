#include <stdio.h>

int Q7_2(void)
{
	char ch;
	int count = 0;
	
	while ((ch = getchar()) != '#')
	{
		printf("%c-%d ", ch, ch);
		if (++count % 8 == 0) printf("\n");
	}

	return 0;
}