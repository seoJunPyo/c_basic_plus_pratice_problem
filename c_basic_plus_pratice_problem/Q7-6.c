#include <stdio.h>

int Q7_6(void)
{
	char cur_ch, prev_ch = NULL;
	int count = 0;

	while ((cur_ch = getchar()) != '#')
	{
		if (cur_ch == 'i' && prev_ch == 'e')
			count++;

		prev_ch = cur_ch;
	}

	printf("ei�� ������ Ƚ�� : %d\n", count);

	return 0;
}