#include <stdio.h>

void critic(int* units);

int Q12_1(void)
{
	int units;

	printf("���� �� �� ������ �� �Ŀ������ �Ƽ���?\n");
	scanf_s("%d", &units);
	while (units != 56)
		critic(&units);
	printf("������ �˰� �־�����!\n");

	return 0;
}

void critic(int * units)
{
	printf("Ʋ�Ƚ��ϴ�. �ٽ� ���纸����!\n");
	scanf_s("%d", units);
}