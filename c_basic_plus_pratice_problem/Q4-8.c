#include <stdio.h>
#include "util.h"
static void scan_int(int* n);


int Q4_8(void)
{
	int mile;
	int gallon;
	int km;
	int liter;
	const int MILE_TO_KM = 1609;
	const int GALLON_TO_LITER = 3785;

	printf("������ �Ÿ� �Է� (����) : ");
	scan_int(&mile);
	km = mile * MILE_TO_KM;

	printf("�Һ��� �ֹ��� �Է� (����) : ");
	scan_int(&gallon);
	liter = gallon * GALLON_TO_LITER;

	printf("100ų�� ���ʹ� �Һ��� �ֹ��� ��(����) : %.1f", ((double)liter / km) * 100);

	return 0;
}
 
static void scan_int(int* n)
{
	while (scanf_s("%d", n) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	eat_chars();
}