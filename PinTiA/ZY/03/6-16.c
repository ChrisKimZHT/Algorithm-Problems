#include <stdio.h>

void printdigits(int n);

int main()
{
	int n;

	scanf("%d", &n);
	printdigits(n);

	return 0;
}

/* 你的代码将被嵌在这里 */
void printdigits(int n)
{
	int digit[100], length = 0;
	if (n == 0)
	{
		printf("0\n");
		return;
	}
	while (n)
	{
		digit[length] = n % 10;
		n /= 10;
		length++;
	}
	for (int i = length - 1; i >= 0; i--)
	{
		printf("%d\n", digit[i]);
	}
	return;
}