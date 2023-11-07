#include <stdio.h>
#include <string.h>
#define SIZE 50
static void scan_string(char string[]);

int Q4_6(void)
{
	char f_name[SIZE] = { 0 };
	char l_name[SIZE] = { 0 };
	int f_name_len;
	int l_name_len;


	printf("성 입력 : ");
	scan_string(l_name);
	l_name_len = (int)strlen(l_name);

	printf("이름 입력 : ");
	scan_string(f_name);
	f_name_len = (int)strlen(f_name);

	printf("%s %s\n", f_name, l_name);
	printf("%*d %*d\n", f_name_len, f_name_len,l_name_len, l_name_len);
	printf("\n");
	printf("%s %s\n", f_name, l_name);
	printf("%-*d %-*d\n", f_name_len, f_name_len, l_name_len, l_name_len);

	return 0;
}

static void scan_string(char string[])
{
	scanf_s("%s", string, SIZE);
	while (getchar() != '\n')
		continue;
}