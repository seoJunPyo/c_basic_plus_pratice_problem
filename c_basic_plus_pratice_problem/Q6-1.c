#include <stdio.h>
#define SIZE 26

int Q6_1(void)
{
	char alphabets[SIZE];
	
	for (int i = 0; i < SIZE; i++)
		alphabets[i] = 'a' + i;


	for (int i = 0; i < SIZE; i++)
		printf("%c ", alphabets[i]);

	return 0;
}