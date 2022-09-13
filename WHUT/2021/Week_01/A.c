#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
		printf("%d\n", a + b);
}