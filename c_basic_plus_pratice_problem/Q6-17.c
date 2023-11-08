#include <stdio.h>

int Q6_17(void)
{
	double my_cash = 1000000;
	double use_cash = 100000;
	int year = 0;

	do
	{
		my_cash = (my_cash + my_cash * 0.08) - use_cash;
		year++;

		printf("%d¿¬Â÷ ³²Àº µ· : %.2f\n", year, my_cash);
	} while (my_cash > 0);

	return 0;
}
