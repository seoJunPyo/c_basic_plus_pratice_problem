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

	printf("���� ������ �Է��Ͻÿ�.\n");
	printf("�������� ������ ���� ��ġ���� [enter] Ű�� �����ÿ�.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("���ڸ��� �Է��Ͻÿ�.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("������ �Է��Ͻÿ�.\n");
		scanf_s("%f", &library[count].value);
		count++;

		while (getchar() != '\n')
			continue;

		if (count < MAXBKS)
			printf("���� ���� ������ �Է��Ͻÿ�.\n");
	}

	printf("���� ��� ������ �����Ͻÿ�.\n");
	printf("c. %-20s t. %-20s\n", "�Է� ��", "���� ��");
	printf("v. %-20s q. %-20s\n", "���� ��", "����");


	while ((choice = getchar()) != 'q')
	{
		switch (choice)
		{
		case 'c':
			printf("������ �����ϰ� �ִ� �������� ����Դϴ�. : \n");
			sort_by_create(library, count);
			break;
		case 't':
			printf("������ �����ϰ� �ִ� �������� ����Դϴ�. : \n");
			sort_by_title(library, count);
			break;
		case 'v':
			printf("������ �����ϰ� �ִ� �������� ����Դϴ�. : \n");
			sort_by_value(library, count);
			break;
		default:
			printf("��ȿ���� ���� �����Դϴ�.\n");
			break;
		}

		while (getchar() != '\n')
			continue;

		printf("\n");
		printf("���� ��� ������ �����Ͻÿ�.\n");
		printf("c. %-20s t. %-20s\n", "�Է� ��", "���� ��");
		printf("v. %-20s q. %-20s\n", "���� ��", "����");
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


