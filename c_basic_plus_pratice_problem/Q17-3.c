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

		if (AddItme_Arr(temp, films) == false)
		{
			fprintf(stderr, "�޸� �Ҵ翡 ���� �߻� \n");
			break;
		}

		if (IsFull_Arr(films))
		{
			puts("����Ʈ�� ���� á���ϴ�.");
			break;
		}

		puts("���� ��ȭ Ÿ��Ʋ�� �Է��Ͻÿ�. (�������� �����) : ");
	}

	if (IsEmpty_Arr(films))
		printf("�Էµ� �����Ͱ� �����ϴ�.\n");
	else
	{
		printf("��ȭ���� ����� ������ �����ϴ�.\n");
		Traverse_Arr(films, showmoives_Arr);
	}

	printf("�� %d���� ��ȭ�� �Է��߽��ϴ�.", List_Item_Count_Arr(films));

	Empty_The_List_Arr(films);
	printf("����!\n");
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
	printf("��ȭ : %s �� : %d\n", item.title, item.rating);
}
