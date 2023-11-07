#include <stdio.h>
#include <ctype.h>
int choice_menu(char* choice);
int input_tall(double* tall);

int Q3_7(void)
{
	double tall;
	char choice;
	const double INCH_TO_CM = 2.54;

	printf("�Է��� Ű ���� ���� : \n");
	printf("c) %-10s i) %-10s\n", "��Ƽ����", "��ġ");
	while (choice_menu(&choice) != 1)
		printf("��ȿ�� �Է��� �ƴմϴ�. �ٽ� �����ϼ���!\n");

	switch (choice)
	{
	case 'c':
		printf("Ű �Է� (��Ƽ����): ");
		input_tall(&tall);
		printf("%.1f��Ƽ���ʹ� %.1f��ġ�Դϴ�.", tall, tall / INCH_TO_CM);
		break;
	case 'i':
		printf("Ű �Է� (��ġ): ");
		input_tall(&tall);
		printf("%.1f��ġ�� %.1f��Ƽ�����Դϴ�.", tall, tall * INCH_TO_CM);
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
		printf("Ű�� ������ ����� �� ���� ���� �Է��߽��ϴ�.\n");
		printf("�ٽ� �Է� : ");
		
		while (getchar() != '\n')
			continue;
	}

	return status;
}