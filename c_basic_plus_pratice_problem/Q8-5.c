#include <stdio.h>
#include <ctype.h>
#include "util.h"

int Q8_5(void)
{
	int guess = 50;
	int max = 100, min = 0;
	char answer;

	printf("����� ������ ���ڴ� %d�Դϴ�!\n", guess);
	printf("�´ٸ� y, ���ٸ� l, ���ٸ� h \n");
	printf("�Է� : ");
	while ((answer = tolower(getchar())) != 'y')
	{
		switch (answer)
		{
		case 'h' :
			min = guess;
			guess = (max + guess) / 2;
			break;
		case 'l' :
			max = guess;
			guess =	(max - min) / 2 + min;
			break;
		default:
			printf("��ȿ�� �Է��� �ƴմϴ�.\n");
			printf("�ٽ� �Է� : ");
			eat_chars();
			continue;
		}

		printf("����� ������ ���ڴ� %d�Դϴ�!\n", guess);
		printf("�´ٸ� y, ���ٸ� l, ���ٸ� h\n");
		printf("�Է� : ");

		eat_chars();
	}

	printf("������ϴ�!\n");

	return 0;
}

