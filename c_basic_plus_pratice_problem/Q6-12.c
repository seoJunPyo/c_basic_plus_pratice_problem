#include <stdio.h>

double infinity_plus(int count);
double infinity_plus_minus(int count);

int Q6_12(void)
{
	int count;
	printf("항 수 입력 : ");
	while (scanf_s("%d", &count) == 1)
	{
		printf("%d항까지의 결산 결과 : \n", count);
		printf("%lf\n", infinity_plus(count));
		printf("%lf\n", infinity_plus_minus(count));
		printf("항 수 입력 : ");
	}

	printf("종료!");
	return 0;
}

double infinity_plus(int count)
{
	double result = 0;

	for (int i = 0; i < count; i++)
		result += i == 0 ? 1.0 : 1.0 / (double)i;

	return result;
}

double infinity_plus_minus(int count)
{
	double result = 0;
	int sign = 1;

	for (int i = 0; i < count; i++)
	{
		result += i == 0 ? 1.0 : (1.0 / (double)i) * sign;
		sign *= -1;
	}

	return result;
}