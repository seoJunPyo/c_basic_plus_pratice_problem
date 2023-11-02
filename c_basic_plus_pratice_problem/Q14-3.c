#include <stdio.h>
#include <string.h>
#include "util.h"

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};


void sort_by_create(struct book[], int);
void sort_by_title(struct book[], int);
void sort_by_value(struct book[], int);

int Q14_3(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index = 0;
	char choice;

	printf("도서 제목을 입력하시오.\n");
	printf("끝내려면 라인의 시작 위치에서 [enter] 키를 누르시오.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("저자명을 입력하시오.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("정가를 입력하시오.\n");
		scanf_s("%f", &library[count].value);
		count++;

		while (getchar() != '\n')
			continue;

		if (count < MAXBKS)
			printf("다음 도서 제목을 입력하시오.\n");
	}

	printf("도서 목록 정렬을 선택하시오.\n");
	printf("c. %-20s t. %-20s\n", "입력 순", "제목 순");
	printf("v. %-20s q. %-20s\n", "가격 순", "종료");


	while ((choice = getchar()) != 'q')
	{
		switch (choice)
		{
		case 'c':
			printf("다음은 소장하고 있는 도서들의 목록입니다. : \n");
			sort_by_create(library, count);
			break;
		case 't':
			printf("다음은 소장하고 있는 도서들의 목록입니다. : \n");
			sort_by_title(library, count);
			break;
		case 'v':
			printf("다음은 소장하고 있는 도서들의 목록입니다. : \n");
			sort_by_value(library, count);
			break;
		default:
			printf("유효하지 않은 선택입니다.\n");
			break;
		}

		while (getchar() != '\n')
			continue;

		printf("\n");
		printf("도서 목록 정렬을 선택하시오.\n");
		printf("c. %-20s t. %-20s\n", "입력 순", "제목 순");
		printf("v. %-20s q. %-20s\n", "가격 순", "종료");
	}


	return 0;
}

void sort_by_create(struct book library[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		printf("%s by%s : %.2f\n", library[i].title, library[i].author, library[i].value);
}

void sort_by_title(struct book library[], int n)
{
	struct book* plibrary[MAXBKS];
	struct book *temp;

	for (int i = 0; i < n; i++)
		plibrary[i] = &library[i];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (strcmp((*plibrary[j]).title, (*plibrary[j + 1]).title) > 0)
			{
				temp = plibrary[j];
				plibrary[j] = plibrary[j + 1];
				plibrary[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d : %s by%s : %.2f\n", i, (*plibrary[i]).title, (*plibrary[i]).author, (*plibrary[i]).value);
}

void sort_by_value(struct book library[], int n)
{
	struct book* plibrary[MAXBKS];
	struct book *temp;

	for (int i = 0; i < n; i++)
		plibrary[i] = &library[i];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if ((*plibrary[j]).value - (*plibrary[j + 1]).value < 0)
			{
				temp = plibrary[j];
				plibrary[j] = plibrary[j + 1];
				plibrary[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d : %s by%s : %.2f\n", i, (*plibrary[i]).title, (*plibrary[i]).author, (*plibrary[i]).value);
}


