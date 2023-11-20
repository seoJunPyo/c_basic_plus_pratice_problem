#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int roll_dice(int dice, int sides);

int Q12_7(void)
{
	int roll_count, dice, sides;
	srand((unsigned int)time(NULL));

	printf("던질 횟수를 입력하시오(끝내려면 q).\n");
	while (scanf_s("%d", &roll_count) == 1 && roll_count != 'q')
	{
		printf("주사위 면수와 던질 주사위 개수를 입력하시오(끝내려면 0) \n");
		while (scanf_s("%d", &sides) != 1) 
		{
			printf("유효한 값이 아닙니다.\n");
			printf("다시 입력 : ");
		}

		if (sides <= 0)
			break;

		while (scanf_s("%d", &dice) != 1)
		{
			printf("유효한 값이 아닙니다.\n");
			printf("다시 입력 : ");

			while (getchar() != '\n')
				continue;
		}

		for (int i = 0; i < roll_count; i++)
		{
			printf("%d ", roll_dice(dice, sides));
			if (i % 5 == 0)
				printf("\n");
		}
		printf("\n");


		while (getchar() != '\n')
			continue;
		printf("던질 횟수를 입력하시오(끝내려면 q).\n");
	}

	printf("종료!\n");

	return 0;
}

int roll_dice(int dice, int sides)
{
	int result = 0;

	for (int i = 0; i < dice; i++)
		result += (rand() % sides) + 1;

	return result;
}