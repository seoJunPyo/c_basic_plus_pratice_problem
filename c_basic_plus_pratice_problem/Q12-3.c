#include <stdio.h>
#include "util.h"

void set_mode(int *mode);
void get_info(int mode, double * distance, double* uesd_oil);
void show_info(int mode, double distance, double used_oil);

int Q12_3(void)
{
	int cur_mode;
	double distance, used_oil;

	printf("������ ���� 0, �̱��� ���� 1�� �Է��Ͻÿ� : ");
	scanf_s("%d", &cur_mode);
	while (cur_mode >= 0)
	{
		set_mode(&cur_mode);
		get_info(cur_mode, &distance, &used_oil);
		show_info(cur_mode, distance, used_oil);
		printf("������ ���� 0, �̱��� ���� 1�� �Է��Ͻÿ�. ");
		printf("(�������� -1) : ");
		scanf_s("%d", &cur_mode);
	}

	printf("����!\n");

	return 0;
}

static void set_mode(int *mode)
{
	static prev_mode = 0;

	if (*mode != 0 && *mode != 1)
	{
		printf("��� ������ �߸��Ǿ����ϴ�.");
		printf("��� %d (%s)�� ����մϴ�.\n", prev_mode, prev_mode == 0 ? "������" : "�̱���");
		*mode = prev_mode;

		return;
	}

	prev_mode = *mode;
}

static void get_info(int mode, double* distance, double* used_oil)
{
	printf("%s ������  ������ �Ÿ� �Է� : ", mode == 0 ? "ų�ι���" : "����");
	while (scanf_s("%lf", distance) != 1)
	{
		printf("��ȿ�� �Է��� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	printf("%s ������ �Һ��� �ֹ��� �Է� : ", mode == 0 ? "����" : "����");
	while (scanf_s("%lf", used_oil) != 1)
	{
		printf("��ȿ�� �Է��� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}
}

static void show_info(int mode, double distance, double used_oil)
{
	if (mode == 0)
		printf("������ : 100ų�ι��ʹ� %.2f���� �Դϴ�.\n", (used_oil / distance) * 100);
	else
		printf("�̱� : ������ %.1f���� �Դϴ�.\n", distance / used_oil);
}