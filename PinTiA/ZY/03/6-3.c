#include <stdio.h>

int fib(int n);

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", fib(n));

	return 0;
}

/* 你的代码将被嵌在这里 */
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	int last = 1, current = 1;
	for (int i = 2; i < n; i++)
	{
		int temp = current;
		current += last;
		last = temp;
	}
	return current;
}