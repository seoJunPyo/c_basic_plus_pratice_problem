#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "util.h"
#include "Q15.h"

#define SIZE CHAR_BIT * sizeof(int) + 1
int get_bit(int num, int idx);

int Q15_4(void)
{
	int num, idx, bit;

	while (scanf_s("%d %d", &num, &idx) == 2)
	{
		bit = get_bit(num, idx);
		printf("%d의 %d번째 비트 : %d\n", num, idx, bit);
	}

	return 0;
}

int get_bit(int num, int idx)
{
	char bin_str[SIZE];
	itobs(num, bin_str);

	printf("%d의 이진수 표기 : %s\n", num, bin_str);
	printf("%d\n", bin_str[idx] - '0');

	return bin_str[idx] - '0';
}

char* itobs(int num, char* bin_str)
{
	int i;
	int  size = SIZE - 1;

	for (i = size - 1; i >= 0; i--, num >>= 1)
		bin_str[i] = (01 & num) + '0';
	bin_str[size] = '\0';

	return bin_str;
}