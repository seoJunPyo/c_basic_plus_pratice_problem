#include "Q17.h"
#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
};

typedef struct film L_Item;

typedef struct tagLNode
{
	L_Item* item;
	struct tagLNode* next;

} L_Node;

char* s_gets(char* st, int n);
void L_add_node(L_Node** head, L_Node* new_node);
L_Node* L_create_node(L_Item* new_item);
void L_print_node(L_Node* head);
L_Item* L_create_film(char* title, int rating);
void L_destroy_List(L_Node* head);
void L_print_node_reverse(L_Node* head);

int Q17_1(void)
{
	L_Node* head = NULL;
	char input[TSIZE];
	int rating;

	puts("첫 번째 영화 타이틀을 입력하시오 : ");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		puts("평가를 입력하시오 (0점에서 10점까지) : ");
		scanf_s("%d", &rating);
		while (getchar() != '\n')
			continue;

		L_add_node(&head, L_create_node(L_create_film(input, rating)));

		puts("다음 영화 타이틀을 입력하시오 (끝내려면 빈 라인) : ");
	}

	L_print_node_reverse(head);
	L_destroy_List(head);

	return 0;
}

void L_add_node(L_Node** head, L_Node* new_node)
{
	L_Node* current = *head;

	if (current == NULL)
	{
		*head = new_node;
		return;
	}

	while (current->next != NULL)
		current = current->next;

	current->next = new_node;
}

L_Node* L_create_node(L_Item *new_item)
{
	L_Node* new_node = (L_Node*)malloc(sizeof(L_Node));
	if (new_node != NULL)
	{
		new_node->item = new_item;
		new_node->next = NULL;
	}

	return new_node;
}

L_Item* L_create_film(char* title, int rating)
{
	L_Item* film = (L_Item*)malloc(sizeof(L_Item));
	if (film != NULL)
	{
		strcpy_s(film->title, TSIZE, title);
		film->rating = rating;
	}

	return film;
}

void L_destroy_List(L_Node* head)
{
	if (head == NULL)
		return;

	L_destroy_List(head->next);
	free(head->item);
	free(head);
}

void L_print_node(L_Node* head)
{
	L_Node* current = head;

	while (current != NULL)
	{
		printf("%s - %d\n", current->item->title, current->item->rating);
		current = current->next;
	}
}

void L_print_node_reverse(L_Node* head)
{
	if (head == NULL)
		return;

	L_print_node_reverse(head->next);
	printf("%s - %d\n", head->item->title, head->item->rating);
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

