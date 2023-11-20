#include <stdio.h>
#include "util.h"

void set_mode(int mode_num);
void get_info(void);
void show_info(void);

static int mode = 0;
double distance, used_oil;

int Q12_2(void)
{
	int mode;

	printf("유럽식 모드는 0, 미국식 모드는 1을 입력하시오 : ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("유럽식 모드는 0, 미국식 모드는 1을 입력하시오. ");
		printf("(끝내려면 -1) : ");
		scanf_s("%d", &mode);
	}
	
	printf("종료!\n");

	return 0;
}

static void set_mode(int mode_num)
{
	if (mode_num != 0 && mode_num != 1)
	{
		printf("모드 지정이 잘못되었습니다.");
		printf("모드 %d (%s)을 사용합니다.\n", mode, mode == 0 ? "유럽식" : "미국식");
		return;
	}

	mode = mode_num;
}

static void get_info(void)
{
	printf("%s 단위로  주행한 거리 입력 : ", mode == 0 ? "킬로미터" : "마일");
	while (scanf_s("%lf", &distance) != 1)
	{
		printf("유효한 입력이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}

	printf("%s 단위로 소비한 휘발유 입력 : ", mode == 0 ? "리터" : "갤런");
	while (scanf_s("%lf", &used_oil) != 1)
	{
		printf("유효한 입력이 아닙니다.\n");
		printf("다시 입력 : ");
		eat_chars();
	}
}

static void show_info(void)
{
	if (mode == 0)
		printf("유럽식 : 100킬로미터당 %.2f리터 입니다.\n", (used_oil / distance) * 100);
	else
		printf("미국 : 갤런당 %.1f마일 입니다.\n", distance / used_oil);
}
