#include "Q13.h"
#define MAX 41

int Q13_9(void)
{
	FILE* fp;
	char word[MAX] = { 0 };
	int idx = 0;

	if (fopen_s(&fp, "wordy", "a+") != 0)
	{
		printf("wordy ������ �� �� �����ϴ�.\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(word, MAX, fp) != NULL)
		idx++;

	puts("���Ͽ� �߰��� �ܾ���� �Է��Ͻÿ�. �Է��� ��������");
	puts("������ ���� ��ġ���� # Ű�� �Է��ϼ���.");
	while ((fscanf_s(stdin, "%40s", word, MAX)) == 1 && (word[0] != '#'))
		fprintf(fp, "%d. %s\n", idx++, word);

	puts("���� ���� : ");
	rewind(fp);
	while (fgets(word, MAX, fp) != NULL)
		puts(word);
	puts("����!");

	if (fclose(fp) != 0)
		fprintf(stderr, "������ �ݴµ� ������ �߻��߽��ϴ�. \n");

	return 0;
}