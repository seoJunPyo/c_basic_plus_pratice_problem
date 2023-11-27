#include <stdio.h>
#define YEARS 5
#define MONTHS 12

void print_year_average_fall(const double rain[YEARS][MONTHS]);
void print_month_average_fall(const double rain[YEARS][MONTHS]);

int Q10_12(void)
{
	const double rain[YEARS][MONTHS] = {
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};

	print_year_average_fall(rain);
	print_month_average_fall(rain);
	printf("\n");

	return 0;
}

static void print_year_average_fall(const double rain[YEARS][MONTHS])
{
	int year, month;
	double subtot, total;

	printf("�⵵  ���췮(��ġ)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += *(*(rain + year) + month);
		printf("%-5d %-15.1f\n", 2010 + year, subtot);
		total += subtot;
	}

	printf("����� ���췮�� %.1f��ġ�Դϴ�.\n\n", total / YEARS);
}

static void print_month_average_fall(const double rain[YEARS][MONTHS])
{
	int year, month;
	double subtot;

	printf("����� ���췮�� ������ �����ϴ�.\n\n");
	printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += *(*(rain + year) + month);
		printf("%-4.1f ", subtot / YEARS);
	}
}