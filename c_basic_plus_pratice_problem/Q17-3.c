#include "Q17.h"
#define TSIZE 45
#define MAXSIZE 100

struct film
{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct list
{
	Item entries[MAXSIZE];
	int items;
} List;

void Init_list_Arr(List** plist);
bool IsEmpty_Arr(const List* plist);
bool IsFull_Arr(const List* plist);
unsigned int List_Item_Count_Arr(const List* plist);
bool AddItme_Arr(Item item, List* plist);
void Traverse_Arr(const List* plist, void(*pfun)(Item item));
void Empty_The_List_Arr(List* plist);
char* s_gets(char* st, int n);
void showmoives_Arr(Item item);

int Q17_3(void)
{
	List* films;
	Item temp;

	Init_list_Arr(&films);
	if (IsFull_Arr(films))
	{
		fprintf(stderr, "메모리가 가득 찼습니다.\n");
		exit(1);
	}

	puts("첫 번쨰 영화 타이틀을 입력하시오 : ");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("평가를 입력하시오 (0점에서 10점까지) : ");
		scanf_s("%d", &temp.rating);
		while (getchar() != '\n')
			continue;

		if (AddItme_Arr(temp, films) == false)
		{
			fprintf(stderr, "메모리 할당에 문제 발생 \n");
			break;
		}

		if (IsFull_Arr(films))
		{
			puts("리스트가 가득 찼습니다.");
			break;
		}

		puts("다음 영화 타이틀을 입력하시오. (끝내려면 빈라인) : ");
	}

	if (IsEmpty_Arr(films))
		printf("입력된 데이터가 없습니다.\n");
	else
	{
		printf("영화들의 목록은 다음과 같습니다.\n");
		Traverse_Arr(films, showmoives_Arr);
	}

	printf("총 %d편의 영화를 입력했습니다.", List_Item_Count_Arr(films));

	Empty_The_List_Arr(films);
	printf("종료!\n");
	return 0;
}

void Init_list_Arr(List** plist)
{
	List* new_list = (List*)malloc(sizeof(List));
	if (new_list != NULL)
	{
		new_list->items = 0;
	}

	(*plist) = new_list;
}

bool IsEmpty_Arr(const List* plist)
{
	return plist->items == 0;
}

bool IsFull_Arr(const List* plist)
{
	return plist->items == MAXSIZE;
}

bool AddItme_Arr(Item item, List* plist)
{
	if (IsFull_Arr(plist))
		return false;

	plist->entries[plist->items] = item;
	plist->items++;
	return true;
}

unsigned int List_Item_Count_Arr(const List* plist)
{
	return plist->items;
}

void Traverse_Arr(const List* plist, void(*pfun)(Item item))
{
	for (int i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]);
}

void Empty_The_List_Arr(List* plist)
{
	free(plist);
}

static char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
	}
	else
		while (getchar() != '\n')
			continue;

	return ret_val;
}

void showmoives_Arr(Item item)
{
	printf("영화 : %s 평가 : %d\n", item.title, item.rating);
}
