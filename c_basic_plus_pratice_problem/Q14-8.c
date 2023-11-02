#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"
#define MAX_SEAT 12
#define MAX_NAME 20

void init_list(FILE*, struct seat[]);
void save_list(FILE*, struct seat[]);
char get_first(void);
void input_seat_num(int* seat_num);
void show_empty_seats_count(struct seat[]);
void show_empty_seats(struct seat[]);
void show_reservation_holders(struct seat[]);
void make_reservation(struct seat[]);
void cancel_reservation(struct seat[]);

static char * airplan_name;

struct seat
{
	int num;
	bool is_reserved;
	char first_name[MAX_NAME];
	char last_name[MAX_NAME];
};

int Q14_8(char * airplan)
{
	FILE *pseats = NULL;
	struct seat seat_list[MAX_SEAT];
	char choice;
	char air[50];
	int i;

	for (i = 0; i < strlen(airplan); i++)
		air[i] = airplan[i];
	air[i] = '\0';
	airplan_name = airplan;

	printf("%s편 비행기 예약입니다.\n", airplan);

	strcat_s(air, 50, ".dat");
	if (fopen_s(&pseats, air, "a+b") != 0)
	{
		puts("seat.dat 파일을 열 수 없습니다");
		exit(EXIT_FAILURE);
	}

	init_list(pseats, seat_list);

	puts("a) 비어 있는 좌석 수 표시");
	puts("b) 비어 있는 좌석 목록 표시");
	puts("c) 예약된 좌적을 고객 이름의 알파벳 순으로 표시");
	puts("d) 좌석 예약");
	puts("e) 예약 취소");
	puts("f) 프로그램 종료");
	while ((choice = get_first()) != 'f')
	{
		switch (choice)
		{
		case 'a' :
			show_empty_seats_count(seat_list);
			break;
		case 'b':
			show_empty_seats(seat_list);
			break;
		case 'c':
			show_reservation_holders(seat_list);
			break;
		case 'd':
			make_reservation(seat_list);
			break;
		case 'e':
			cancel_reservation(seat_list);
			break;
		default:
			printf("유효한 옵션이 아닙니다.\n");
			printf("다시 선택해 주세요.\n");
			break;
		}

		puts("a) 비어 있는 좌석 표시");
		puts("b) 비어 있는 좌석 목록 표시");
		puts("c) 예약된 좌적을 고객 이름의 알파벳 순으로 표시");
		puts("d) 좌석 예약");
		puts("e) 예약 취소");
		puts("f) 현재 예약 종료");
	}
	fclose(pseats);
	save_list(pseats, seat_list);
	puts("예약 종료.");
	
	return 0;
}

void init_list(FILE *pseats, struct seat seat_list[])
{
	struct seat temp;
	int idx = 0;

	for (int i = 0; i < MAX_SEAT; i++)
	{
		seat_list[i].num = i + 1;
		seat_list[i].is_reserved = false;
		seat_list[i].first_name[0] = '\0';
		seat_list[i].last_name[0] = '\0';
	}

	while (fread(&temp, sizeof(struct seat), 1, pseats) == 1)
	{
		strncpy_s(seat_list[temp.num - 1].first_name, MAX_NAME, temp.first_name, MAX_NAME);
		strncpy_s(seat_list[temp.num - 1].last_name, MAX_NAME, temp.last_name, MAX_NAME);
		if (temp.first_name[0] != '\0') seat_list[temp.num - 1].is_reserved = true;
	}
}

void save_list(FILE* pseats, struct seat seat_list[])
{
	if (fopen_s(&pseats, "seat.dat", "wb") != 0)
	{
		puts("seat.dat 파일을 열 수 없습니다");
		exit(EXIT_FAILURE);
	}

	fwrite(seat_list, sizeof(struct seat), MAX_SEAT, pseats);
	fclose(pseats);
}

void show_empty_seats_count(struct seat seat_list[])
{
	int sum = 0;
	
	for (int i = 0; i < MAX_SEAT; i++)
		if (!seat_list[i].is_reserved)
			sum++;

	printf("%s편 - 현재 비어 있는 좌석의 수는 %d입니다.\n", airplan_name, sum);
}

void show_empty_seats(struct seat seat_list[])
{
	printf("%s편 - 현재 비어 있는 좌석 리스트\n", airplan_name);

	for (int i = 0; i < MAX_SEAT; i++)
		if (!seat_list[i].is_reserved)
			printf("- %d 좌석\n", i + 1);
}

void show_reservation_holders(struct seat seat_list[])
{
	struct seat* plist[MAX_SEAT];
	struct seat* temp;
	int count = 0;

	for (int i = 0; i < MAX_SEAT; i++)
	{
		if (seat_list[i].is_reserved)
		{
			plist[count] = &seat_list[i];
			count++;
		}
	}

	if (count == 0)
	{
		puts("아직 예약한 고객이 없습니다.");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (strcmp((*plist[j]).last_name, (*plist[j + 1]).last_name) > 0)
			{
				temp = plist[0];
				plist[0] = plist[1];
				plist[1] = temp;
			}
		}
	}


	for (int i = 0; i < count; i++)
			printf("%s %s : %d번 좌석\n",(*plist[i]).first_name, (*plist[i]).last_name, (*plist[i]).num);
}

void make_reservation(struct seat seat_list[])
{
	int seat_num;
	int choice;

	do
	{
		printf("예약하려는 좌석을 선택해주세요. : ");
		input_seat_num(&seat_num);

		while (seat_list[seat_num - 1].is_reserved)
		{
			printf("이미 예약된 좌석 입니다. 다시 입력해 주세요. : ");
			input_seat_num(&seat_num);
		}

		printf("선택하신 좌석은 %s편 %d입니다.\n",airplan_name, seat_num);
		printf("1. %-20s 2. %-20s\n", "다음", "다시 선택");
		scanf_s("%d", &choice);
		eat_chars();
	} while (choice == 2);

	do
	{
		printf("예약자 성 입력 : ");
		s_gets(seat_list[seat_num - 1].last_name, MAX_NAME);
		printf("예약자 이름 입력 : ");
		s_gets(seat_list[seat_num - 1].first_name, MAX_NAME);

		printf("예약자 성함은 %s %s입니다.\n", seat_list[seat_num - 1].last_name, seat_list[seat_num - 1].first_name);
		printf("1. %-20s 2. %-20s\n", "완료", "다시 입력");
		scanf_s("%d", &choice);
		eat_chars();
	} while (choice == 2);


	printf("%s %s 고객님,%s편 %d번 좌석 예약 완료되었습니다.\n", seat_list[seat_num - 1].first_name, seat_list[seat_num - 1].last_name, airplan_name, seat_num);
	seat_list[seat_num - 1].is_reserved = true;
}

void cancel_reservation(struct seat seat_list[])
{
	int seat_num;
	int choice;

	do
	{
		printf("취소하려는 좌석을 선택해주세요. : ");
		input_seat_num(&seat_num);

		if (!seat_list[seat_num - 1].is_reserved)
		{
			puts("예약되지 않은 좌석입니다.");
			return;
		}

		printf("%s편 %d번 좌석 %s %s이 예약하신 좌석입니다. 취소하시겠습니까?\n", airplan_name, seat_num, seat_list[seat_num - 1].last_name, seat_list[seat_num - 1].first_name);
		printf("1. %-20s 2. %-20s\n", "취소하기", "다시 선택");
		scanf_s("%d", &choice);
		eat_chars();
	} while (choice == 2);

	printf("%s %s 고객님,%s편 %d번 좌석 예약 취소되었습니다.\n", seat_list[seat_num - 1].first_name, seat_list[seat_num - 1].last_name, airplan_name, seat_num);
	seat_list[seat_num - 1].first_name[0] = '\0';
	seat_list[seat_num - 1].last_name[0] = '\0';
	seat_list[seat_num - 1].is_reserved = false;
}

void input_seat_num(int* seat_num)
{
	while (scanf_s("%d", seat_num) != 1 || *seat_num > MAX_SEAT || *seat_num < 1)
	{
		printf("유효하지 않은 좌석입니다. 다시 입력해주세요. : ");
		eat_chars();
	}
}