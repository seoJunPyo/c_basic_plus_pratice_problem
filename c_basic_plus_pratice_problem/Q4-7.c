#include <stdio.h>
#include <float.h>

int Q4_7(void)
{
	double db = 1.0 / 3.0;
	float fl = 1.0 / 3.0;

	for (int i = 0; i < 3; i++)
		printf("double : %.4f, float : %.4f\n", db, fl);
	putchar('\n');

	for (int i = 0; i < 3; i++)
		printf("double : %.12f, float : %.12f\n", db, fl);
	putchar('\n');

	for (int i = 0; i < 3; i++)
		printf("double : %.16f, float : %.16f\n", db, fl);
	putchar('\n');

	printf("FLT_DIG : %d, DBL_DIG : %d\n", FLT_DIG, DBL_DIG);

	return 0;
}