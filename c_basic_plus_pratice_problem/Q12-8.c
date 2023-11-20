#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int* make_array(int elem, int val);
void show_array(const int arr[], int n);

int Q12_8(void)
{
	int* pa;
	int size;
	int value;

	printf("������ ������ �Է��Ͻÿ� : ");
	while (scanf_s("%d", &size) == 1 && size > 0)
	{
		printf("�ʱ�ȭ ���� �Է��Ͻÿ� : ");

		scanf_s("%d", &value);
		pa = make_array(size, value);

		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}


		printf("������ ������ �Է��Ͻÿ� : ");
	}

	printf("����!\n");

	return 0;
}

int* make_array(int elem, int val)
{
	int* arr = (int*)malloc(sizeof(int) * elem);

	if (arr != NULL)
		for (int i = 0; i < elem; i++)
			*(arr + i) = val;

	return arr;
}

void show_array(const int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 8 == 0 && i != 0)
			printf("\n");

		printf("%d ", arr[i]);
	}

	printf("\n");
}