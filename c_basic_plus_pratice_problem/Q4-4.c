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

	printf("�̸� �Է� : ");
	scanf_s("%s", name, SIZE);
	eat_chars();

	show_menu();
	select_menu(&choice);
	printf("Ű �Է� (%s) : ", choice == 'c' ? "��Ƽ����" : "��ġ");
	input_tall(&tall);

	printf("%s��,", name);
	printf(" ����� Ű�� %f%s�Դϴ�.\n", tall / (choice == 'c' ? M_TO_CM : FEAT_TO_INCH), choice == 'c' ? "����" : "��Ʈ");

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
	printf("Ű ���� ���� : \n");
	printf("i) %-10s c) %-10s\n", "��ġ", "��Ƽ����");
}

void select_menu(char* ch)
{
	while ((*ch = get_char() != 'i') && *ch != 'c')
	{
		printf("��ȿ�� ������ �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
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
		printf("Ű�� ������ ����� �� ���� ���� �Է��߽��ϴ�.\n");
		printf("�ٽ� �Է� : ");
	}
}