#include <stdio.h>
#include <math.h>

void transform(double nums[], double target[], int n, double (*fp)(double));

int Q14_11(void)
{ 
	double nums[91];
	double target[91];

	for (int i = 0; i < 91; i++)
		nums[i] = i;

	for (int i = 0; i < 4; i++)
		transform(nums, target, 91, sin);
	for (int i = 0; i < 91; i++)
		printf("%.2f ", target[i]);

	printf("\n\n");

	for (int i = 0; i < 4; i++)
		transform(nums, target, 91, cos);
	for (int i = 0; i < 91; i++)
		printf("%.2f ", target[i]);

	return 0;
}

void transform(double nums[], double target[], int n, double (*fp)(double))
{
	for (int i = 0; i < n; i++)
		target[i] = fp(nums[i]);
}