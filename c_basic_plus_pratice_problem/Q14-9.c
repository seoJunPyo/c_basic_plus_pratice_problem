#include <stdio.h>
#include "Q14.h"

int Q14_9(void)
{
	char* airplanes[4] = { "102", "311", "444", "519" };
	int choice;

	puts("예약하실 비행기 편을 선택하세요.");
	printf("1) %-20s 2) %-20s\n", airplanes[0], airplanes[1]);
	printf("3) %-20s 4) %-20s\n", airplanes[2], airplanes[3]);
	printf("5) 종료\n");

	do {
		while (scanf_s("%d", &choice) != 1 || choice < 1 || choice > 5)
			printf("유효하지 않는 입력입니다. 다시 선택 : ");
		if (choice == 5)
			continue;

		Q14_8(airplanes[choice - 1]);

		puts("예약하실 비행기 편을 선택하세요.");
		printf("1) %-20s 2) %-20s\n", airplanes[0], airplanes[1]);
		printf("3) %-20s 4) %-20s\n", airplanes[2], airplanes[3]);
		printf("5) 종료\n");

	} while (choice != 5);


	puts("종료.");

	return 0;
}