#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "util.h"

#define SIZE CHAR_BIT * sizeof(int) + 1

int bin_to_dec(char* bin_str);
bool check_bin(char* bin_str);

int Q15_1(void)
{
	char bin_str[SIZE];
	printf("%zu �ڸ� ������ �Է� : ", SIZE - 1);
	while (s_gets(bin_str, SIZE) && bin_str[0] != '\0')
	{
		if (!check_bin(bin_str))
			puts("�������� �ƴմϴ�.");
		else
			printf("�������� ��ȯ�ϸ� %d�Դϴ�.\n", bin_to_dec(bin_str));

		puts("���� ������ �Է�");
	}

	return 0;
}

int bin_to_dec(char* bin_str)
{
	int val = 0;

	while (*bin_str != '\0')
		val = 2 * val + (*bin_str++ - '0');

	return val;
}

bool check_bin(char* bin_str)
{
	bool is_bin = true;

	while (*bin_str != '\0' && is_bin)
	{
		if (*bin_str != '0' && *bin_str != '1')
			is_bin = false;

		bin_str++;
	}

	return is_bin;
}