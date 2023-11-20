#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int Q12_9(void)
{
	int word_count;
	char** words;
	char word[256] = { 0 };

	printf("How many words do you wish to enter? : ");
	while (scanf_s("%d", &word_count) == 1 && word_count > 0)
	{
		words = (char**)malloc(sizeof(char*) * word_count);

		if (words != NULL)
		{
			for (int i = 0; i < word_count; i++)
			{
				if (scanf_s("%s", word, 256) == 1)
				{
					*(words + i) = (char*)malloc(strlen(word) + 1);
					strncpy_s(*(words + i), strlen(word) + 1, word, 256);
				}
			}

			printf("Here are your words : \n");
			for (int i = 0; i < word_count; i++)
				printf("%s\n", *(words + i));
		}
	}

	return 0;
}