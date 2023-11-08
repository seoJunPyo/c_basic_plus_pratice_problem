#include <stdio.h>
#include "util.h"

double get_cm(void);

int Q5_4(void)
{
	double cm;
	const double CM_TO_FEAT = 30.48;
	const double CM_TO_INCH = 2.54;

	while ((cm = get_cm()) > 0)
		printf("%.1f��Ƽ���ʹ� %.0f��Ʈ, %.1f��ġ�Դϴ�.\n", cm, cm / CM_TO_FEAT, cm / CM_TO_INCH);

	return 0;
}

double get_cm(void)
{
	double cm;
	
	printf("��Ƽ���� ������ Ű �Է� : ");
	while (scanf_s("%lf", &cm) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	eat_chars();

	return cm;
}