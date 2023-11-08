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

	printf("�ְ� �뵿 �ð� �Է� : ");
	while (scanf_s("%d", &work_time) != 1)
	{
		printf("��ȿ�� ���� �ƴճ���.\n");
		printf("�ٽ� �Է� : ");
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

	printf("�� �ҵ� : %f\n���� : %f\n���ҵ� : %f\n\n", gross_pay, taxes, net_pay);

	return 0;
}