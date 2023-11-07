#include <stdio.h>
#include <string.h>
#define SIZE 50

int Q4_2(void)
{
	char name[SIZE] = { 0 };
	int width;

	printf("이름 입력 : ");
	scanf_s("%s", name, SIZE);
	width = strlen(name) + 3;

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%-*s\"\n", width, name);
	return 0;
}