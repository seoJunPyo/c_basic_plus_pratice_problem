#include <stdio.h>

int Q3_4(void)
{
	float num;
	
	printf("�Ǽ� �Է� : ");
	scanf_s("%f", &num);

	printf("�����Ҽ��� ǥ�� : %f\n", num);
	printf("���� ǥ�� : %e\n", num);
	printf("p ǥ�� : %a\n", num);

	return 0;
}