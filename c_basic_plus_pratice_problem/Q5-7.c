#include <stdio.h>
#include "util.h"

float cube(float fl);

int Q5_7(void)
{
	float fl;

	printf("�Ǽ� �Է� : ");
	while (scanf_s("%f", &fl) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
	}

	printf("%f�� �������� %f�Դϴ�.\n", fl, cube(fl));

	return 0;
}

float cube(float fl)
{
	return fl * fl * fl;
}