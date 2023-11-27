#include "Q14.h"

static int Days_Sum_by_Month_Str(char* Month_Str);
static int Days_Sum_by_Month_Num(int Month_Num);

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

struct Month_Data
{
	int num;
	char str[20];
	enum { NUM = 0, STR = 1} data_type;
};

int Q14_2(void)
{
	struct Month_Data month_data;
	int year, day, days;

	printf("���� �Է� : ");
	scanf_s("%d", &year);

	printf("�� �Է� : ");
	if (scanf_s("%d", &month_data.num) == 1)
		month_data.data_type = NUM;
	else
	{
		scanf_s("%s", month_data.str, 20);
		month_data.data_type = STR;
	}

	printf("�� �Է� : ");
	scanf_s("%d", &day);

	days = month_data.data_type == STR ? Days_Sum_by_Month_Str(month_data.str) + day : Days_Sum_by_Month_Num(month_data.num) + day;
			
	printf("%d�� ", year);
	if (month_data.data_type == STR)
		printf("%s ", month_data.str);
	else
		printf("%d��", month_data.num);
	printf("%d�� ���� ���� �� ���� %d�Դϴ�.", day, days);

	return 0;
}

static int Days_Sum_by_Month_Str(char* Month_Str)
{
	int sum = 0;
	int is_Month_Str = 0;

	for (int i = 0; i < 12; i++)
	{
		if (strcmp(Month_Str, Months[i].Name) == 0 || strcmp(Month_Str, Months[i].Short_Name) == 0)
		{
			is_Month_Str = 1;
			break;
		}

		sum += Months[i].Days;
	}


	if (is_Month_Str == 0)
	{
		printf("�߸��� �Է��Դϴ�.\n");
		return -1;
	}

	return sum;
}

static int Days_Sum_by_Month_Num(int Month_Num)
{
	int sum = 0;

	if (Month_Num < 1 || Month_Num > 12)
	{
		printf("�� ������ ��� �����Դϴ�.\n");
		return -1;
	}

	for (int i = 0; i < Month_Num - 1; i++)
		sum += Months[i].Days;

	return sum;
}

