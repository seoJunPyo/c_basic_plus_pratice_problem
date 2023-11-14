#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 2
#define MAX_STRLEN 256

char get_first(void);
char* s_gets(char* Buffer, int MaxCount, FILE* Stream);
void show_input_menu(void);
void show_sort_menu(void);
void input_str(char str[SIZE][MAX_STRLEN], FILE* fp);
char** copy_pointer(char str[][MAX_STRLEN], int len);
void swap_char_pointer(char** ptr1, char** ptr2);
int  get_first_word_len(char* str);
void print_str_list(char str[][MAX_STRLEN], int len);
void print_by_ascii(char str[][MAX_STRLEN], int len);
void print_by_strlen(char str[][MAX_STRLEN], int len);
void print_by_first_word_len(char str[][MAX_STRLEN], int len);

int Q11_11(void)
{
	FILE* fp;
	char f_name[MAX_STRLEN] = { 0 };
	char str[SIZE][MAX_STRLEN];
	int i = 0;
	char ch;

	show_input_menu();
	while ((ch = get_first()) != 'q')
	{
		switch (ch)
		{
		case 'a':
			printf("파일 명 입력 : ");
			scanf_s("%s", f_name, MAX_STRLEN);

			if (fopen_s(&fp, f_name, "r") != 0)
			{
				printf("%s 파일을 열 수 없습니다.\n", f_name);
				exit(EXIT_FAILURE);
			}
			break;

		case 'b' : 
			fp = stdin;
			break;

		default:
			printf("유효한 선택이 아닙니다.\n");
			printf("입력 방식 선택 : ");
			continue;
		}

		input_str(str, fp);

		show_sort_menu();
		while ((ch = get_first()) != 'q')
		{
			switch (ch)
			{
			case 'a':
				print_str_list(str, SIZE);
				break;

			case 'b':
				print_by_ascii(str, SIZE);
				break;

			case 'c':
				print_by_strlen(str, SIZE);
				break;
			case 'd':
				print_by_first_word_len(str, SIZE);
				break;

			default:
				printf("유효한 선택이 아닙니다.\n");
				printf("정렬 방식 선택 : ");
				continue;
			}

			show_sort_menu();
		}

		show_input_menu();
	}
	
	
	printf("종료!");

	return 0;
}

static char * s_gets(char* Buffer, int MaxCount, FILE* Stream)
{
	char* result;
	result = fgets(Buffer, MaxCount, Stream);
	Buffer[strlen(Buffer) - 1] = '\0';

	return result;
}

static char get_first(void)
{
	char ch;

	while (isspace(ch = getchar()))
		continue;

	while (getchar() != '\n')
		continue;

	return ch;
}

void show_input_menu(void)
{
	printf("a) %-10s b) %-10s q) %-10s\n", "파일 입력", "표준 입력", "종료");
	printf("입력 방식 선택 : ");
}

void show_sort_menu(void)
{
	printf("a) %-20s b) %-20s\n", "입력 순", "ASCII 조회 순");
	printf("c) %-20s d) %-20s\n", "문자열 길이 순", "첫 단어 길이 순");
	printf("q) %-20s\n", "종료");
	printf("정렬 방식 선택 : ");
}

void input_str(char str[SIZE][MAX_STRLEN], FILE * fp)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d번째 문자열 입력 : ", i + 1);
		s_gets(str[i], MAX_STRLEN, fp);
		if (fp != stdin)
			printf("%s\n", str[i]);
	}
}

char** copy_pointer(char str[][MAX_STRLEN], int len)
{
	char** ptr = (char**)malloc(sizeof(char*) * len);

	if (ptr != NULL)
	{
		for (int i = 0; i < len; i++)
			ptr[i] = str[i];
	}

	return ptr;
}

void swap_char_pointer(char** ptr1, char** ptr2)
{
	char* temp;

	temp = *(ptr1);
	*(ptr1) = *(ptr2);
	*(ptr2) = temp;
}

int  get_first_word_len(char* str)
{
	int count = 0;

	while (*(str + count) != ' ')
		count++;

	return count;
}

void print_str_list(char str[][MAX_STRLEN], int len)
{
	for (int i = 0; i < len; i++)
		printf("%s\n", *(str + i));
}


void print_by_ascii(char str[][MAX_STRLEN], int len)
{
	char **ptr = copy_pointer(str, len);

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - i - 1; j++)
			if (strcmp(*(ptr + j), *(ptr + j + 1)) > 0)
				swap_char_pointer(ptr + j, ptr + j + 1);
		
	for (int i = 0; i < len; i++)
		printf("%s\n", *(ptr + i));

	free(ptr);
}

void print_by_strlen(char str[][MAX_STRLEN], int len)
{
	char **ptr = copy_pointer(str, len);

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - i - 1; j++)
			if (strlen(*(ptr +j)) < strlen(*(ptr + j + 1)))
				swap_char_pointer(ptr + j, ptr + j + 1);

	for (int i = 0; i < len; i++)
		printf("%s\n", *(ptr + i));

	free(ptr);
}

void print_by_first_word_len(char str[][MAX_STRLEN], int len)
{
	char **ptr = copy_pointer(str, len);

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - i - 1; j++)
			if (get_first_word_len(*(ptr + j)) < get_first_word_len(*(ptr + j + 1)))
				swap_char_pointer(ptr + j, ptr + j + 1);

	for (int i = 0; i < len; i++)
		printf("%s\n", *(ptr + i));

	free(ptr);
}





