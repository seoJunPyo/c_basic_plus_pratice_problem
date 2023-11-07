#include <stdio.h>
#include <ctype.h>
int choice_menu(char* choice);
int input_tall(double* tall);

int Q3_7(void)
{
	double tall;
	char choice;
	const double INCH_TO_CM = 2.54;

	printf("입력할 키 단위 선택 : \n");
	printf("c) %-10s i) %-10s\n", "센티미터", "인치");
	while (choice_menu(&choice) != 1)
		printf("유효한 입력이 아닙니다. 다시 선택하세요!\n");

	switch (choice)
	{
	case 'c':
		printf("키 입력 (센티미터): ");
		input_tall(&tall);
		printf("%.1f센티미터는 %.1f인치입니다.", tall, tall / INCH_TO_CM);
		break;
	case 'i':
		printf("키 입력 (인치): ");
		input_tall(&tall);
		printf("%.1f인치는 %.1f센티미터입니다.", tall, tall * INCH_TO_CM);
		break;
	default:
		break;
	}

	return 0;
}

int choice_menu(char* choice)
{
	int status;
	status = scanf_s("%c", choice, 1);
	while (getchar() != '\n')
		continue;

	if (status != 1)
		return status;

	if (tolower(*choice) != 'c' && tolower(*choice) != 'i')
		return 0;

	return 1;
}

int input_tall(double* tall)
{
	int status;

	while ((status = scanf_s("%lf", tall)) != 1)
	{
		printf("키의 값으로 사용할 수 없는 것을 입력했습니다.\n");
		printf("다시 입력 : ");
		
		while (getchar() != '\n')
			continue;
	}

	return status;
}