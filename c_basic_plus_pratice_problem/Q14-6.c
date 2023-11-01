#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 20
#define MAX_FILE 50
#define MAX_PLAYER 19

struct player {
	int uniform_num;
	char fname[MAX_NAME];
	char lname[MAX_NAME];
	int at_bats, hits, walks, RBIs;
	float batting_avarage;
};


int Q14_6(void)
{
	FILE* player_file;
	char fname[MAX_FILE] = { 0 };
	struct player player_list[MAX_PLAYER];
	struct player total_record;
	int uniform_num = 0, at_bats, hits, walks, RBIs;

	printf("선수 목록 파일 명 입력 : ");
	scanf_s("%s", fname, MAX_FILE);
	if (fopen_s(&player_file, fname, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", fname);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAX_PLAYER; i++)
	{
		player_list[i].uniform_num = NULL;
		player_list[i].at_bats = 0;
		player_list[i].hits = 0;
		player_list[i].walks = 0;
		player_list[i].RBIs = 0;
	}

	while (fscanf_s(player_file, "%d", &uniform_num) == 1)
	{
		fscanf_s(player_file, "%s", player_list[uniform_num].fname, MAX_NAME);
		fscanf_s(player_file, "%s", player_list[uniform_num].lname, MAX_NAME);
		fscanf_s(player_file, "%d", &at_bats);
		fscanf_s(player_file, "%d", &hits);
		fscanf_s(player_file, "%d", &walks);
		fscanf_s(player_file, "%d", &RBIs);
		
		player_list[uniform_num].uniform_num = uniform_num;
		player_list[uniform_num].at_bats += at_bats;
		player_list[uniform_num].hits += hits;
		player_list[uniform_num].walks += walks;
		player_list[uniform_num].RBIs += RBIs;
	}

	for (int i = 0; i < MAX_PLAYER; i++)
		player_list[i].batting_avarage = (float)player_list[i].hits / player_list[i].at_bats;

	for (int i = 0; i < MAX_PLAYER; i++)
	{
		if (player_list[i].uniform_num == NULL)
			continue;

		printf("%s %s 선수의 기록 : \n", player_list[i].lname, player_list[i].fname);
		printf("타수 : %-20d 안타 : %-20d\n", player_list[i].at_bats, player_list[i].hits);
		printf("볼넷 : %-20d 타점 : %-20d\n", player_list[i].walks, player_list[i].RBIs);
		printf("타율 : %.3f\n", player_list[i].batting_avarage);
		printf("\n");
	}

	total_record.at_bats = total_record.hits = total_record.walks = total_record.RBIs = 0;
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		if (player_list[i].uniform_num == NULL)
			continue;

		total_record.at_bats += player_list[i].at_bats;
		total_record.hits += player_list[i].hits;
		total_record.walks += player_list[i].walks;
		total_record.RBIs += player_list[i].RBIs;
	}
	total_record.batting_avarage = (float)total_record.hits / total_record.at_bats;

	printf("팀 전체 기록 : ");
	printf("타수 : %-20d 안타 : %-20d\n", total_record.at_bats, total_record.hits);
	printf("볼넷 : %-20d 타점 : %-20d\n", total_record.walks, total_record.RBIs);
	printf("타율 : %.3f\n", total_record.batting_avarage);
	printf("\n");


	return 0;
}

