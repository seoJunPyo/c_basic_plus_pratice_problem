#include <stdio.h>

double infinity_plus(int count);
double infinity_plus_minus(int count);

int Q6_12(void)
{
	int count;
	printf("�� �� �Է� : ");
	while (scanf_s("%d", &count) == 1)
	{
		printf("%d�ױ����� ��� ��� : \n", count);
		printf("%lf\n", infinity_plus(count));
		printf("%lf\n", infinity_plus_minus(count));
		printf("�� �� �Է� : ");
	}

	printf("����!");
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