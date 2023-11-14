#include <stdio.h>

int Q11_13(int argc, char * argv[])
{
	for (int i = argc - 1; i > 0; i--)
		printf("%s ", argv[i]);

	return 0;
}