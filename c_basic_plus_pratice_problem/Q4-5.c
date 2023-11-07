#include <stdio.h>
#include "util.h"

void input_float(float* fl);

int Q4_5(void)
{
	float Mbs;
	float file_size;
	const float BYTE_TO_BIT = 8;

	printf("다운로드 속도 (Mbs) : ");
	input_float(&Mbs);

	printf("다운받을 파일 크기 (MB) : ");
	input_float(&file_size);
	
	printf("초당 %.2f 메가비트, %.2f 메가바이트 파일을\n", Mbs, file_size);
	printf("%.2f초에 다운로드한다.\n", (file_size * BYTE_TO_BIT) / Mbs);
	
	return 0;
}

void input_float(float* fl)
{
	while (scanf_s("%f", fl) != 1)
	{
		printf("유효한 값이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	eat_chars();
}