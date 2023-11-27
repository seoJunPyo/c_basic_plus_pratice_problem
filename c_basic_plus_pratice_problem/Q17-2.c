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
		fprintf(stderr, "�޸𸮰� ���� á���ϴ�.\n");
		exit(1);
	}

	puts("ù ���� ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ� : ");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("�򰡸� �Է��Ͻÿ� (0������ 10������) : ");
		scanf_s("%d", &temp.rating);
		while (getchar() != '\n')
			continue;

		if (AddItme(temp, films) == false)
		{
			fprintf(stderr, "�޸� �Ҵ翡 ���� �߻� \n");
			break;
		}

		if (IsFull(films))
		{
			puts("����Ʈ�� ���� á���ϴ�.");
			break;
		}

		puts("���� ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ�. (�������� �����) : ");
	}

	if (IsEmpty(films))
		printf("�Էµ� �����Ͱ� �����ϴ�.\n");
	else
	{
		printf("��ȭ���� ����� ������ �����ϴ�.\n");
		Traverse(films, showmoives);
	}

	printf("�� %d���� ��ȭ�� �Է��߽��ϴ�.", List_Item_Count(films));

	Empty_The_List(films);
	printf("����!\n");
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
	printf("��ȭ : %s �� : %d\n", item.title, item.rating);
}

