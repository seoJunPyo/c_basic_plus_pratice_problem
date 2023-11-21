#include "Q13.h"
#define MAX 41

int Q13_9(void)
{
	FILE* fp;
	char word[MAX] = { 0 };
	int idx = 0;

	if (fopen_s(&fp, "wordy", "a+") != 0)
	{
		printf("wordy 파일을 열 수 없습니다.\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(word, MAX, fp) != NULL)
		idx++;

	puts("파일에 추가할 단어들을 입력하시오. 입력을 끝내려면");
	puts("라인의 시작 위치에서 # 키를 입력하세요.");
	while ((fscanf_s(stdin, "%40s", word, MAX)) == 1 && (word[0] != '#'))
		fprintf(fp, "%d. %s\n", idx++, word);

	puts("파일 내용 : ");
	rewind(fp);
	while (fgets(word, MAX, fp) != NULL)
		puts(word);
	puts("종료!");

	if (fclose(fp) != 0)
		fprintf(stderr, "파일을 닫는데 에러가 발생했습니다. \n");

	return 0;
}