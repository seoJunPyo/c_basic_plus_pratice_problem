#include "Q17.h"
#define MAXLEN 256

typedef struct node
{
	char data;
	struct node* next;
} Node;

typedef struct stack
{
	Node* top;
	int items;
} Stack;

Stack* ST_create_stack(void);
Node* ST_creat_node(char data);
void ST_push(Stack* st, Node* new_node);
Node* ST_pop(Stack* st);
void ST_print_stack(Stack* st);
void ST_destory_stack(Stack* st);

int Q17_5(void)
{
	char input[MAXLEN];
	char * str, * find;
	Stack *stack = ST_create_stack();

	puts("뒤집을 문자열 입력 : ");
	str = fgets(input, MAXLEN - 1, stdin);
	if (str)
	{
		find = strchr(input, '\n');
		if (find)
			*find = '\0';
	}
	
	for (int i = 0; i < strlen(input); i++)
		ST_push(stack, ST_creat_node(input[i]));

	ST_print_stack(stack);
	ST_destory_stack(stack);

	return 0;
}

Stack* ST_create_stack(void)
{
	Stack *new_st = (Stack*)malloc(sizeof(Stack));
	if (new_st != NULL)
	{
		new_st->top = NULL;
		new_st->items = 0;
	}

	return new_st;
}

Node* ST_creat_node(char data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
	}

	return new_node;
}

void ST_push(Stack* st, Node* new_node)
{
	if (st->top == NULL)
		st->top = new_node;
	else
	{
		new_node->next = st->top;
		st->top = new_node;
	}

	st->items++;
}

Node* ST_pop(Stack* st)
{
	Node* Popped;

	if (st->top == NULL)
		return NULL;

	Popped = st->top;
	st->top = st->top->next;
	st->items--;

	return Popped;
}

void ST_print_stack(Stack* st)
{
	Node* current = st->top;

	while (st != NULL)
	{
		printf("%c", current->data);
		current = current->next;
	}
}

void ST_destory_stack(Stack* st)
{
	Node* Popped;

	while ((Popped = ST_pop(st)) != NULL)
		free(Popped);

	free(st);
}
