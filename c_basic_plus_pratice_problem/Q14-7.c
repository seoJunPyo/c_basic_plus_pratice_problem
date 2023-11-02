#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	bool is_delete;
};

int Q14_7(void)
{
	struct book library[MAXBKS];
	struct book temp;
	int count = 0, delete_count = 0;
	int idx, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);
	int choice;

	if (fopen_s(&pbooks, "book.dat", "a+b") != 0)
	{
		fputs("book.dat ������ �� �� �����ϴ�.\n", stderr);
		exit(1);
	}
	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("book.dat�� ���� ��� �ִ� ���� : ");
		printf("%d. %s by %s : %.2f\n",count, library[count].title, library[count].author, library[count].value);
		printf("1. %-10s 2. %-10s 3. %-10s\n", "����", "����", "����");
		while (scanf_s("%d", &choice) != 1 || 1 > choice || 3 < choice)
		{
			printf("��ȿ�� ������ �ƴմϴ�. �ٽ� ����  : ");

			while (getchar() != '\n')
				continue;
		}

		while (getchar() != '\n')
			continue;

		switch (choice)
		{
		case 1 :
			library[count].is_delete = false;
			count++;
			break;
		case 2 :
			puts("���� �� ���� �Է� (�� ���� �Է� �� �ǳʶٱ�) : ");
			s_gets(temp.title, MAXTITL);
			puts("���� �� ���� �Է� (�� ���� �Է� �� �ǳʶٱ�) : ");
			s_gets(temp.author, MAXAUTL);
			puts("���� �� ���� �Է� (-1 �Է� �� �ǳʶٱ�) : ");
			scanf_s("%f", &temp.value);

			while (getchar() != '\n')
				continue;

			if (temp.title[0] != '\0')
				strncpy_s(library[count].title, MAXTITL, temp.title, MAXTITL);
			if (temp.author[0] != '\0')
				strncpy_s(library[count].author, MAXAUTL, temp.author, MAXAUTL);
			if (temp.value >= 0)
				library[count].value = temp.value;
			count++;
			break;

		case 3 :
			library[count].is_delete = true;
			delete_count++;
			count++;
			break;
		default:
			break;
		}
	}
	filecount = count;
	if (count - delete_count == MAXBKS)
	{
		fputs("book.dat ������ ���� á��.", stderr);
		exit(2);
	}

	for (idx = 0; idx < filecount; idx++)
	{
		if (library[idx].is_delete)
		{
			count = idx;
			break;
		}
	}
		
	printf("count : %d \n", count);

	puts("�� ���� ������� �Է��Ͻÿ�.");
	puts("�������� ������ ���� ��ġ���� [enter] Ű�� �����ÿ�.");
	while (count < MAXBKS && gets_s(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		bool has_delete = false;

		printf("count : %d \n", count);
		puts("���ڸ��� �Է��Ͻÿ�.");
		s_gets(library[count].author, MAXAUTL);
		puts("������ �Է��Ͻÿ�.");
		scanf_s("%f", &library[count].value);
		library[count].is_delete = false;

		for (idx = count; idx < filecount; idx++)
			if (library[idx].is_delete)
			{
				has_delete = true;
				break;
			}

		count = has_delete ? idx : count + 1;

		while (getchar() != '\n')
			continue;

		if (count < MAXBKS)
			puts("���� ������ �Է��Ͻÿ�.");
	}

	fclose(pbooks);
	if (fopen_s(&pbooks, "book.dat", "wb") != 0)
	{
		fputs("book.dat ������ �� �� �����ϴ�.\n", stderr);
		exit(1);
	}

	if (count > 0)
	{
		puts("������ �����ϰ� �ִ� �������� ����Դϴ�.");
		for (idx = 0; idx < count; idx++)
		{
			if (library[idx].is_delete) continue;
			printf("%s by %s : %.2f\n", library[idx].title, library[idx].author, library[idx].value);
			fwrite(&library[idx], size, 1, pbooks);
		}
	}
	else
	{
		puts("å�� �����ϴ�.");
	}

	puts("��.");
	fclose(pbooks);

	return 0;
}