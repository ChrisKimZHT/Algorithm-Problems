#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("Today, I ate %d apple", x);
	if (x > 1)
	{
		printf("s.");
	}
	else
	{
		printf(".");
	}
	return 0;
}