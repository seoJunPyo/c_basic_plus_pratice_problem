#include <stdio.h>
#define SIZE 50

int Q4_1(void)
{
	char f_name[SIZE];
	char l_name[SIZE];

	printf("이름 입력 : ");
	scanf_s("%s", l_name, SIZE);
	printf("성 입력 : ");
	scanf_s("%s", f_name, SIZE);

	printf("%s %s\n", l_name, f_name);

	return 0;
}