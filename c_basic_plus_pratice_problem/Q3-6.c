#include <stdio.h>

int Q3_6(void)
{
	const double WATER_MASS = 3.0E-23;
	const int QUERT_FOR_GRAM = 950;
	int quert;



	printf("���� �� �Է� (quert) : ");
	scanf_s("%d", &quert);

	printf("%d��Ʈ ���� %d�׷��̴�.\n", quert, quert * QUERT_FOR_GRAM);
	printf("%d�׷��� ���� %f���� ���ڰ� ����ִ�.\n", quert * QUERT_FOR_GRAM, (quert * QUERT_FOR_GRAM) / WATER_MASS);

	return 0;
}