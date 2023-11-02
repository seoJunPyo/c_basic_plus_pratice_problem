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

	printf("%s�� ����� �����Դϴ�.\n", airplan);

	strcat_s(air, 50, ".dat");
	if (fopen_s(&pseats, air, "a+b") != 0)
	{
		puts("seat.dat ������ �� �� �����ϴ�");
		exit(EXIT_FAILURE);
	}

	init_list(pseats, seat_list);

	puts("a) ��� �ִ� �¼� �� ǥ��");
	puts("b) ��� �ִ� �¼� ��� ǥ��");
	puts("c) ����� ������ �� �̸��� ���ĺ� ������ ǥ��");
	puts("d) �¼� ����");
	puts("e) ���� ���");
	puts("f) ���α׷� ����");
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
			printf("��ȿ�� �ɼ��� �ƴմϴ�.\n");
			printf("�ٽ� ������ �ּ���.\n");
			break;
		}

		puts("a) ��� �ִ� �¼� ǥ��");
		puts("b) ��� �ִ� �¼� ��� ǥ��");
		puts("c) ����� ������ �� �̸��� ���ĺ� ������ ǥ��");
		puts("d) �¼� ����");
		puts("e) ���� ���");
		puts("f) ���� ���� ����");
	}
	fclose(pseats);
	save_list(pseats, seat_list);
	puts("���� ����.");
	
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
		puts("seat.dat ������ �� �� �����ϴ�");
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

	printf("%s�� - ���� ��� �ִ� �¼��� ���� %d�Դϴ�.\n", airplan_name, sum);
}

void show_empty_seats(struct seat seat_list[])
{
	printf("%s�� - ���� ��� �ִ� �¼� ����Ʈ\n", airplan_name);

	for (int i = 0; i < MAX_SEAT; i++)
		if (!seat_list[i].is_reserved)
			printf("- %d �¼�\n", i + 1);
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
		puts("���� ������ ���� �����ϴ�.");
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
			printf("%s %s : %d�� �¼�\n",(*plist[i]).first_name, (*plist[i]).last_name, (*plist[i]).num);
}

void make_reservation(struct seat seat_list[])
{
	int seat_num;
	int choice;

	do
	{
		printf("�����Ϸ��� �¼��� �������ּ���. : ");
		input_seat_num(&seat_num);

		while (seat_list[seat_num - 1].is_reserved)
		{
			printf("�̹� ����� �¼� �Դϴ�. �ٽ� �Է��� �ּ���. : ");
			input_seat_num(&seat_num);
		}

		printf("�����Ͻ� �¼��� %s�� %d�Դϴ�.\n",airplan_name, seat_num);
		printf("1. %-20s 2. %-20s\n", "����", "�ٽ� ����");
		scanf_s("%d", &choice);
		eat_chars();
	} while (choice == 2);

	do
	{
		printf("������ �� �Է� : ");
		s_gets(seat_list[seat_num - 1].last_name, MAX_NAME);
		printf("������ �̸� �Է� : ");
		s_gets(seat_list[seat_num - 1].first_name, MAX_NAME);

		printf("������ ������ %s %s�Դϴ�.\n", seat_list[seat_num - 1].last_name, seat_list[seat_num - 1].first_name);
		printf("1. %-20s 2. %-20s\n", "�Ϸ�", "�ٽ� �Է�");
		scanf_s("%d", &choice);
		eat_chars();
	} while (choice == 2);


	printf("%s %s ����,%s�� %d�� �¼� ���� �Ϸ�Ǿ����ϴ�.\n", seat_list[seat_num - 1].first_name, seat_list[seat_num - 1].last_name, airplan_name, seat_num);
	seat_list[seat_num - 1].is_reserved = true;
}

void cancel_reservation(struct seat seat_list[])
{
	int seat_num;
	int choice;

	do
	{
		printf("����Ϸ��� �¼��� �������ּ���. : ");
		input_seat_num(&seat_num);

		if (!seat_list[seat_num - 1].is_reserved)
		{
			puts("������� ���� �¼��Դϴ�.");
			return;
		}

		printf("%s�� %d�� �¼� %s %s�� �����Ͻ� �¼��Դϴ�. ����Ͻðڽ��ϱ�?\n", airplan_name, seat_num, seat_list[seat_num - 1].last_name, seat_list[seat_num - 1].first_name);
		printf("1. %-20s 2. %-20s\n", "����ϱ�", "�ٽ� ����");
		scanf_s("%d", &choice);
		eat_chars();
	} while (choice == 2);

	printf("%s %s ����,%s�� %d�� �¼� ���� ��ҵǾ����ϴ�.\n", seat_list[seat_num - 1].first_name, seat_list[seat_num - 1].last_name, airplan_name, seat_num);
	seat_list[seat_num - 1].first_name[0] = '\0';
	seat_list[seat_num - 1].last_name[0] = '\0';
	seat_list[seat_num - 1].is_reserved = false;
}

void input_seat_num(int* seat_num)
{
	while (scanf_s("%d", seat_num) != 1 || *seat_num > MAX_SEAT || *seat_num < 1)
	{
		printf("��ȿ���� ���� �¼��Դϴ�. �ٽ� �Է����ּ���. : ");
		eat_chars();
	}
}