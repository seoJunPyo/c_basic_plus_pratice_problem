#include <stdio.h>
#include <ctype.h>
#include "util.h"

int Q8_5(void)
{
	int guess = 50;
	int max = 100, min = 0;
	char answer;

	printf("당신이 생각한 숫자는 %d입니다!\n", guess);
	printf("맞다면 y, 낮다면 l, 높다면 h \n");
	printf("입력 : ");
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
			printf("유효한 입력이 아닙니다.\n");
			printf("다시 입력 : ");
			eat_chars();
			continue;
		}

		printf("당신이 생각한 숫자는 %d입니다!\n", guess);
		printf("맞다면 y, 낮다면 l, 높다면 h\n");
		printf("입력 : ");

		eat_chars();
	}

	printf("맞췄습니다!\n");

	return 0;
}

