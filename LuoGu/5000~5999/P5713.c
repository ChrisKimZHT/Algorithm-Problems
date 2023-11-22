#include <stdio.h>

int main(void)
{
	int x, a, b;
	scanf("%d", &x);
	a = 5 * x;
	b = 11 + 3 * x;
	if (a < b)
	{
		printf("Local");
	}
	else
	{
		printf("Luogu");
	}
	return 0;
}