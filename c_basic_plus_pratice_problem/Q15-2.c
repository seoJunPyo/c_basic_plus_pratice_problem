#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "util.h"
#include "Q15.h"

#define SIZE CHAR_BIT * sizeof(int) + 1

int bin_to_dec(char* bin_str);
bool check_bin(char* bin_str);
char* deci_to_bin(char bin_str[], int deci);
void reverse(char arr[], int len);


int Q15_2(int argc, char *argv[])
{
	int val1, val2;
	char bin_str[SIZE];

	if (!check_bin(argv[1]) || !check_bin(argv[2]))
		puts("이진수가 아닙니다.");
	else
	{
		val1 = bin_to_dec(argv[1]);
		val2 = bin_to_dec(argv[2]);

		deci_to_bin(bin_str, val1 & val2);
		printf("& 연산 결과 : %s\n", bin_str);

		deci_to_bin(bin_str, val1 | val2);
		printf("| 연산 결과 : %s\n", bin_str);

		deci_to_bin(bin_str, val1 ^ val2);
		printf("^ 연산 결과 : %s\n", bin_str);
	}

	return 0;
}

char* deci_to_bin(char bin_str[], int deci)
{
	int i = 0;

	while (deci > 0)
	{
		bin_str[i++] = deci % 2 == 0 ? '0' : '1';
		deci >>= 1;
	}
	bin_str[i] = '\0';
	reverse(bin_str, i);

	return bin_str;
}

void reverse (char arr[], int len)
{
	char temp;

	for (int i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}