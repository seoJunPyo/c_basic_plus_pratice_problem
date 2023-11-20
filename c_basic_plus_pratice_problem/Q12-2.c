#include <stdio.h>
#include "util.h"

void set_mode(int mode_num);
void get_info(void);
void show_info(void);

static int mode = 0;
double distance, used_oil;

int Q12_2(void)
{
	int mode;

	printf("������ ���� 0, �̱��� ���� 1�� �Է��Ͻÿ� : ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("������ ���� 0, �̱��� ���� 1�� �Է��Ͻÿ�. ");
		printf("(�������� -1) : ");
		scanf_s("%d", &mode);
	}
	
	printf("����!\n");

	return 0;
}

static void set_mode(int mode_num)
{
	if (mode_num != 0 && mode_num != 1)
	{
		printf("��� ������ �߸��Ǿ����ϴ�.");
		printf("��� %d (%s)�� ����մϴ�.\n", mode, mode == 0 ? "������" : "�̱���");
		return;
	}

	mode = mode_num;
}

static void get_info(void)
{
	printf("%s ������  ������ �Ÿ� �Է� : ", mode == 0 ? "ų�ι���" : "����");
	while (scanf_s("%lf", &distance) != 1)
	{
		printf("��ȿ�� �Է��� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	printf("%s ������ �Һ��� �ֹ��� �Է� : ", mode == 0 ? "����" : "����");
	while (scanf_s("%lf", &used_oil) != 1)
	{
		printf("��ȿ�� �Է��� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}
}

static void show_info(void)
{
	if (mode == 0)
		printf("������ : 100ų�ι��ʹ� %.2f���� �Դϴ�.\n", (used_oil / distance) * 100);
	else
		printf("�̱� : ������ %.1f���� �Դϴ�.\n", distance / used_oil);
}
