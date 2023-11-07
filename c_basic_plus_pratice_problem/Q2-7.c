#include <stdio.h>
void smile(void);

int Q2_7(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j > i; j--)
			smile();
		printf("\n");
	}

	return 0;
}

void smile(void)
{
	printf("Smile!");
}