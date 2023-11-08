#include <stdio.h>
#define BASE_PAY 10.00
#define MAX_TIME 40
#define OVERTIME_PAY BASE_PAY * 1.5
#define GRADE_A 300
#define GRADE_B 150
#define TAX_RATE_A 0.15
#define TAX_RATE_B 0.2
#define TAX_RATE_C 0.25



int Q7_7(void)
{
	int work_time;
	double gross_pay, taxes, net_pay;

	printf("주간 노동 시간 입력 : ");
	while (scanf_s("%d", &work_time) != 1)
	{
		printf("유효한 값이 아닙나다.\n");
		printf("다시 입력 : ");
	}

	if (work_time <= MAX_TIME)
		gross_pay = work_time * BASE_PAY;
	else
		gross_pay = MAX_TIME * BASE_PAY + (work_time - MAX_TIME) * OVERTIME_PAY;

	if (gross_pay <= GRADE_A)
		taxes = gross_pay * TAX_RATE_A;
	else if (gross_pay <= GRADE_A + GRADE_B)
		taxes = GRADE_A * TAX_RATE_A + (gross_pay - GRADE_A) * TAX_RATE_B;
	else 
		taxes = GRADE_A * TAX_RATE_A + GRADE_B * TAX_RATE_B + (gross_pay - GRADE_A - GRADE_B) * TAX_RATE_C;

	net_pay = gross_pay - taxes;

	printf("총 소득 : %f\n세금 : %f\n순소득 : %f\n\n", gross_pay, taxes, net_pay);

	return 0;
}