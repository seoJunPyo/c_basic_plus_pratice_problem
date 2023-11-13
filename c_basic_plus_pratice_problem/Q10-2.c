#include <stdio.h>

void copy_arr(double target[], double source[], int len);
void copy_ptr(double target[], double source[], int len);
void copy_ptr_at(double target[], double source[], double* last_el);
static void print_arr(double arr[], int len);

int Q10_2(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptr_at(target3, source, source + 5);

	print_arr(target1, 5);
	printf("\n");
	print_arr(target2, 5);
	printf("\n");
	print_arr(target3, 5);
	printf("\n");

	return 0;
}

static void copy_arr(double target[], double source[], int len)
{
	for (int i = 0; i < len; i++)
		target[i] = source[i];
}

static void copy_ptr(double target[], double source[], int len)
{
	for (int i = 0; i < len; i++)
		*(target + i) = *(source + i);
}

static void copy_ptr_at(double target[], double source[], double * last_el)
{
	for (int i = 0; source + i != last_el; i++)
		*(target + i) = *(source + i);
}

static void print_arr(double arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%f ", arr[i]);
}