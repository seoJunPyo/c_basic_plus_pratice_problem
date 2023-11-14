#include <stdio.h>
#include <stdlib.h>

static double pow(double num, int n);

int Q11_14(int argc, char* argv[])
{
	printf("%s¿« %s¿∫ %f", argv[1], argv[2], pow(atof(argv[1]), atoi(argv[2])));

	return 0;
}
 
static double pow(double num, int n)
{
	if (n == 0) return 1;

	return num * pow(num, n - 1);
}