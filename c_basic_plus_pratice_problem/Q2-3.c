#include <stdio.h>

const int YEAR_DAYS = 365;

int Q2_3(void)
{
	int age_years;
	int age_days;

	printf("�ڽ��� ���� �Է� : ");
	scanf_s("%d", &age_years);
	age_days = age_years * YEAR_DAYS;

	printf("%d����� �뷫 %d�� ��ҽ��ϴ�.\n", age_years, age_days);

	return 0;
}