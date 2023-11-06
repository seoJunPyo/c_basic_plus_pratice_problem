#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "util.h"
#include "Q15.h"

#define SIZE CHAR_BIT * sizeof(int) + 1

void rotate_l(int n, int count);

int Q15_5(void)
{
	rotate_l(25, 4);
	return 0;
}

void rotate_l(int n, int count)
{
	char bin_str[SIZE];

	itobs(n, bin_str);
	itobs(n << count | bin_to_dec(bin_str + SIZE - 1 - count), bin_str);

	printf("%s\n", bin_str);
	putchar('\n');

}