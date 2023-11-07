#include <stdio.h>
#include <ctype.h>
#include "util.h"
#define SIZE 50

char get_char(void);
void show_menu(void);
void select_menu(char* ch);
int scanf_float(float* tall);
void input_tall(float* tall);

int Q4_4(void)
{
	char name[SIZE];
	float tall;
	char choice;
	const float M_TO_CM = 100;
	const float FEAT_TO_INCH = 12;

	printf("이름 입력 : ");
	scanf_s("%s", name, SIZE);
	eat_chars();

	show_menu();
	select_menu(&choice);
	printf("키 입력 (%s) : ", choice == 'c' ? "센티미터" : "인치");
	input_tall(&tall);

	printf("%s씨,", name);
	printf(" 당신의 키는 %f%s입니다.\n", tall / (choice == 'c' ? M_TO_CM : FEAT_TO_INCH), choice == 'c' ? "미터" : "피트");

	return 0;
}

char get_char(void)
{
	char ch;
	ch = getchar();
	eat_chars();

	return tolower(ch);
}

void show_menu(void)
{
	printf("키 단위 선택 : \n");
	printf("i) %-10s c) %-10s\n", "인치", "센티미터");
}

void select_menu(char* ch)
{
	while ((*ch = get_char() != 'i') && *ch != 'c')
	{
		printf("유효한 선택이 아닙니다.\n");
		printf("다시 입력 : ");
	}
}

static int scanf_float(float* fl)
{
	int status;

	status = scanf_s("%f", fl);
	eat_chars();

	return status;
}

static void input_tall(float* tall)
{
	while (scanf_float(tall) != 1)
	{
		printf("키의 값으로 사용할 수 없는 것을 입력했습니다.\n");
		printf("다시 입력 : ");
	}
}