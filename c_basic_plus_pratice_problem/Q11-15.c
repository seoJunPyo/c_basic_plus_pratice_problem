#include <stdio.h>
#include <string.h>
#include <ctype.h>

int myatoi(char* str);

int Q11_15(void)
{
	printf("%d" , myatoi("-12350"));
	return 0;
}

int myatoi(char* str)
{
	int result = 0, pos = 1;
	
	for (int i = (int)strlen(str) - 1; i >= 0; i--)
	{
		if (!isdigit(str[i]) && str[i] != '-')
			return 0;

		else if (i == 0 && str[i] == '-')
			result *= -1;

		else
		{
			result += (str[i] - '0') * pos;
			pos *= 10;
		}
	}
	
	return result;
}