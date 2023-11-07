#include <stdio.h>

int Q2_1(void)
{
	char* first_name = "jun pyo";
	char* last_name = "seo";

	printf("%s %s\n", first_name, last_name);
	printf("%s\n%s\n", first_name, last_name);
	printf("%s ", first_name);
	printf("%s", last_name);

	return 0;
}