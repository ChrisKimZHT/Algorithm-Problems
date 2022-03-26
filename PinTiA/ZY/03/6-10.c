#include <stdio.h>

void hollowPyramid(int n);

int main()
{
	int n;

	scanf("%d", &n);
	hollowPyramid(n);

	return 0;
}

/* 你的代码将被嵌在这里 */
void hollowPyramid(int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		printf(" ");
	}
	printf("1\n");
	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		printf("%d", i);
		for (int j = 1; j <= (i - 1) * 2 - 1; j++)
		{
			printf(" ");
		}
		printf("%d\n", i);
	}
	for (int i = 1; i <= 2 * n - 1 && n != 1; i++)
	{
		printf("%d", n);
	}
}