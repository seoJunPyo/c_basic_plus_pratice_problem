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
		fputs("book.dat 파일을 열 수 없습니다.\n", stderr);
		exit(1);
	}
	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("book.dat에 현재 들어 있는 내용 : ");
		printf("%d. %s by %s : %.2f\n",count, library[count].title, library[count].author, library[count].value);
		printf("1. %-10s 2. %-10s 3. %-10s\n", "다음", "수정", "삭제");
		while (scanf_s("%d", &choice) != 1 || 1 > choice || 3 < choice)
		{
			printf("유효한 선택이 아닙니다. 다시 선택  : ");

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
			puts("수정 할 제목 입력 (빈 라인 입력 시 건너뛰기) : ");
			s_gets(temp.title, MAXTITL);
			puts("수정 할 저자 입력 (빈 라인 입력 시 건너뛰기) : ");
			s_gets(temp.author, MAXAUTL);
			puts("수정 할 가격 입력 (-1 입력 시 건너뛰기) : ");
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
		fputs("book.dat 파일이 가득 찼다.", stderr);
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

	puts("새 도서 제목들을 입력하시오.");
	puts("끝내려면 라인의 시작 위치에서 [enter] 키를 누르시오.");
	while (count < MAXBKS && gets_s(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		bool has_delete = false;

		printf("count : %d \n", count);
		puts("저자명을 입력하시오.");
		s_gets(library[count].author, MAXAUTL);
		puts("정가를 입력하시오.");
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
			puts("다음 제목을 입력하시오.");
	}

	fclose(pbooks);
	if (fopen_s(&pbooks, "book.dat", "wb") != 0)
	{
		fputs("book.dat 파일을 열 수 없습니다.\n", stderr);
		exit(1);
	}

	if (count > 0)
	{
		puts("다음은 소장하고 있는 도서들의 목록입니다.");
		for (idx = 0; idx < count; idx++)
		{
			if (library[idx].is_delete) continue;
			printf("%s by %s : %.2f\n", library[idx].title, library[idx].author, library[idx].value);
			fwrite(&library[idx], size, 1, pbooks);
		}
	}
	else
	{
		puts("책이 없습니다.");
	}

	puts("끝.");
	fclose(pbooks);

	return 0;
}