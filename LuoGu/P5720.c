#include <stdio.h>

int main(void)
{
	int a, i;
	scanf("%d", &a);
	for (i = 1; a > 1; i++)
	{
		a /= 2;
	}
	printf("%d", i);
	return 0;
}