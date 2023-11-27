#include "Q17.h"
#define TSIZE 45

struct film
{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct list
{
	Node* head;
	Node* end;
} List;

void Init_list(List** plist);
bool IsEmpty(const List* plist);
bool IsFull(const List* plist);
unsigned int List_Item_Count(const List* plist);
bool AddItme(Item item, List* plist);
void Traverse(const List* plist, void(*pfun)(Item item));
void Empty_The_List(List* plist);
char* s_gets(char* st, int n);
void showmoives(Item item);

int Q17_2(void)
{
	List* films;
	Item temp;

	Init_list(&films);
	if (IsFull(films))
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

		if (AddItme(temp, films) == false)
		{
			fprintf(stderr, "메모리 할당에 문제 발생 \n");
			break;
		}

		if (IsFull(films))
		{
			puts("리스트가 가득 찼습니다.");
			break;
		}

		puts("다음 영화 타이틀을 입력하시오. (끝내려면 빈라인) : ");
	}

	if (IsEmpty(films))
		printf("입력된 데이터가 없습니다.\n");
	else
	{
		printf("영화들의 목록은 다음과 같습니다.\n");
		Traverse(films, showmoives);
	}

	printf("총 %d편의 영화를 입력했습니다.", List_Item_Count(films));

	Empty_The_List(films);
	printf("종료!\n");
	return 0;
}

void Init_list(List** plist)
{
	List* new_list = (List*)malloc(sizeof(List));
	if (new_list != NULL)
	{
		new_list->head = NULL;
		new_list->end = NULL;
		(*plist) = new_list;
	}
}

bool IsEmpty(const List* plist)
{
	return plist->head == NULL;
}

bool IsFull(const List* plist)
{
	Node* pt;
	bool full;

	pt = (Node*)malloc(sizeof(Node));
	full = pt == NULL;
	free(pt);

	return full;
}

bool AddItme(Item item, List* plist)
{
	Node* pnew;
	
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;

	pnew->item = item;
	pnew->next = NULL;
	
	if (plist->head == NULL)
	{
		plist->head = pnew;
		plist->end = pnew;
	}
	else
	{
		plist->end->next = pnew;
		plist->end = pnew;
	}

	return true;
}

unsigned int List_Item_Count(const List* plist)
{
	Node* current = plist->head;
	unsigned int count = 0;	

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}

void Traverse(const List* plist, void(*pfun)(Item item))
{
	Node* current = plist->head;

	while (current != NULL)
	{
		(*pfun)(current->item);
		current = current->next;
	}
}

void Empty_The_List(List* plist)
{
	Node* save;

	while (plist->head != NULL)
	{
		save = plist->head->next;
		free(plist->head);
		plist->head = save;
	}

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

void showmoives(Item item)
{
	printf("영화 : %s 평가 : %d\n", item.title, item.rating);
}

