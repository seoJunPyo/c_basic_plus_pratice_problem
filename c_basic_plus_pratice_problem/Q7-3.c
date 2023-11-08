#include <stdio.h>

int Q7_3(void)
{
	int even_sum = 0, even_count = 0, odd_sum = 0, odd_count = 0;
	int num;

	printf("Á¤¼ö ÀÔ·Â : ");
	while (scanf_s("%d", &num) == 1 && num != 0)
	{
		if (num % 2 == 0)
		{
			even_sum += num;
			even_count++;
		}
		else
		{
			odd_sum += num;
			odd_count++;
		}

		printf("Á¤¼ö ÀÔ·Â : ");
	}
	
	printf("Â¦¼ö °³¼ö : %d, Â¦¼ö Æò±Õ : %d\n", even_count, even_sum / even_count);
	printf("È¦¼ö °³¼ö : %d, È¦¼ö Æò±Õ : %d\n", odd_count, odd_sum / odd_count);

	return 0;
}