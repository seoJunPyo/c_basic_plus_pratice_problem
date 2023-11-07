#include <stdio.h>

int Q3_6(void)
{
	const double WATER_MASS = 3.0E-23;
	const int QUERT_FOR_GRAM = 950;
	int quert;



	printf("물의 양 입력 (quert) : ");
	scanf_s("%d", &quert);

	printf("%d쿼트 물은 %d그램이다.\n", quert, quert * QUERT_FOR_GRAM);
	printf("%d그램의 물에 %f개의 분자가 들어있다.\n", quert * QUERT_FOR_GRAM, (quert * QUERT_FOR_GRAM) / WATER_MASS);

	return 0;
}