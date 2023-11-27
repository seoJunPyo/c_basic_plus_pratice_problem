#include "Q14.h"

int Get_To_Month_Days(char* Month_Str);

static Month_Info Months[12] = {
	{1, 31, "January", "Jan"},
	{2, 28, "February", "Feb"},
	{3, 31, "March", "Mar"},
	{4, 30, "April", "Apr"},
	{5, 31, "May", "May"},
	{6, 30, "June", "Jun"},
	{7, 31, "July", "Jul"},
	{8, 31, "August", "Aug"},
	{9, 30, "September", "Sep"},
	{10, 31, "October", "Oct"},
	{11, 30, "November", "Nov"},
	{12, 31, "December", "Dec"},
};

int Q14_1(void)
{
	int Days = Get_To_Month_Days("January");

	return 0;
}

static int Get_To_Month_Days(char* Month_Str)
{
	int sum = 0;
	int is_Month_Str = 0;

	for (int i = 0; i < 12; i++)
	{
		sum += Months[i].Days;
		if (strcmp(Month_Str, Months[i].Name) == 0)
		{
			is_Month_Str = 1;
			break;
		}
	}

	if (is_Month_Str == 0)
	{
		printf("잘못된 입력입니다.\n");
		return -1;
	}

	return sum;
}