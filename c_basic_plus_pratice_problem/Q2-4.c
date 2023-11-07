#include <stdio.h>
void jolly(void);
void deny(void);

int Q2_4(void)
{
	jolly();
	jolly();
	jolly();
	deny();

	return 0;
}

void jolly(void)
{
	printf("For he`s jolly good fellow!\n");
}

void deny(void)
{
	printf("Which nobody can deny!\n");
}