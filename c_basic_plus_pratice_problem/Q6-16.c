#include <stdio.h>

int Q6_16(void)
{
	double simple = 100, compound = 100;
	int year = 0;

	do
	{
		simple += 100 * 0.1;
		compound += compound * 0.05;
		year++;

		printf("%d년차, 복리 : %f 단리 : %f\n", year, simple, compound);
	} while (simple > compound);

	return;
}

