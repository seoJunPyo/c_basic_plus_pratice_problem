#include <stdio.h>

int Q3_5(void)
{
	int age;
	const double YEAR_SECONDS = 3.156E7;
	printf("����� ���� �Է� : ");
	scanf_s("%d", &age);

	printf("%d���� �뷫 %f�� ��ҽ��ϴ�.\n", age, age * YEAR_SECONDS);

	return 0;
}