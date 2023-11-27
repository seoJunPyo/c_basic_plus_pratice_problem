#include "Q17.h"
#define MAX_LEN 256

typedef struct item
{
	char* word;
	int count;
} Item;

typedef struct node
{
	Item *item;
	struct node* left;
	struct node* right;
} Node;

Item* BT_create_item(char* word);
Node* BT_create_node(Item* item);
void BT_add_node(Node** tree, Node* new_node);
Node* BT_search_node(Node* tree, char* target);
void BT_destory_tree(Node* tree);
void BT_print_tree(Node* tree, int dept);
static void show_menu(void);

int Q17_7(void)
{
	Node* tree = NULL;
	char input[MAX_LEN];
	char f_name[MAX_LEN] = { 0 };
	FILE* fp;
	int choice;
	Node* find;

	printf("읽을 파일 명 입력 : ");
	scanf_s("%s", f_name, MAX_LEN - 1);
	while (getchar() != '\n')
		continue;

	if (fopen_s(&fp, f_name, "r") != 0)
	{
		printf("%s 파일을 열 수 없습니다.\n", f_name);
		exit(EXIT_FAILURE);
	}

	while (fscanf_s(fp, "%s", input, MAX_LEN - 1) != EOF)
	{
		Item* new_item = BT_create_item(input);
		BT_add_node(&tree, BT_create_node(new_item));
	}

	show_menu();
	while (scanf_s("%d", &choice) == 1 && choice != 3)
	{
		switch (choice)
		{
		case 1 :
			BT_print_tree(tree, 0);
			break;
		case 2:
			printf("찾을 단어 입력 : ");
			scanf_s("%s", input, MAX_LEN);
			while (getchar() != '\n')
				continue;

			find = BT_search_node(tree, input);
			if (find != NULL)
				printf("찾은 단어 %s는 총 %d번 발생했습니다.\n", find->item->word, find->item->count);
			else
				printf("찾는 단어 %s가 없습니다.\n", input);
			break;
		default:
			printf("유효한 선택이 아닙니다.\n");
			break;
		}

		show_menu();
	}

	return 0;
}

Item* BT_create_item(char* word)
{
	Item* new_item = (Item*)malloc(sizeof(Item));
	if (new_item != NULL)
	{
		new_item->word = (char *)malloc(sizeof(char) * (strlen(word) + 1));
		new_item->count = 1;

		if (new_item->word != NULL)
			strcpy_s(new_item->word, strlen(word) + 1, word);
	}

	return new_item;
}

Node* BT_create_node(Item *item)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = item;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

void BT_add_node(Node** tree, Node * new_node)
{
	if (*tree == NULL)
	{
		*tree = new_node;
		return;
	}

	if (strcmp(new_node->item->word, (*tree)->item->word) > 0)
		BT_add_node(&(*tree)->right, new_node);
	else if (strcmp(new_node->item->word, (*tree)->item->word) < 0)
		BT_add_node(&(*tree)->left, new_node);
	else
		(*tree)->item->count++;
}

Node* BT_search_node(Node* tree, char* target)
{
	if (tree == NULL)
		return NULL;

	if (strcmp(tree->item->word, target) == 0)
		return tree;
	else if (strcmp(tree->item->word, target) > 0)
		return BT_search_node(tree->right, target);
	else
		return BT_search_node(tree->left, target);
}

void BT_destory_tree(Node* tree)
{
	if (tree == NULL)
		return;

	BT_destory_tree(tree->left);
	BT_destory_tree(tree->right);
	free(tree->item->word);
	free(tree->item);
	free(tree);
}

void BT_print_tree(Node* tree, int dept)
{
	if (tree == NULL)
		return;

	BT_print_tree(tree->left, dept + 1);

	for (int i = 0; i < dept; i++)
		printf("  ");
	printf("단어 : %s, 발생 횟수 : %d\n", tree->item->word, tree->item->count);

	BT_print_tree(tree->right, dept + 1);
}
 
static void show_menu(void)
{
	printf("1) 모든 단어의 목록 보기\n");
	printf("2) 특정 단어 발생 횟수 보기\n");
	printf("3) 종료\n");
}