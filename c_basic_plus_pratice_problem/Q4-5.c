#include <stdio.h>
#include "util.h"

void input_float(float* fl);

int Q4_5(void)
{
	float Mbs;
	float file_size;
	const float BYTE_TO_BIT = 8;

	printf("�ٿ�ε� �ӵ� (Mbs) : ");
	input_float(&Mbs);

	printf("�ٿ���� ���� ũ�� (MB) : ");
	input_float(&file_size);
	
	printf("�ʴ� %.2f �ް���Ʈ, %.2f �ް�����Ʈ ������\n", Mbs, file_size);
	printf("%.2f�ʿ� �ٿ�ε��Ѵ�.\n", (file_size * BYTE_TO_BIT) / Mbs);
	
	return 0;
}

void input_float(float* fl)
{
	while (scanf_s("%f", fl) != 1)
	{
		printf("��ȿ�� ���� �ƴմϴ�.\n");
		printf("�ٽ� �Է� : ");
		eat_chars();
	}

	eat_chars();
}