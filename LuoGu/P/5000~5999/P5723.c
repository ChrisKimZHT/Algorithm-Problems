#include <stdio.h>

int main(void)
{
	int L, sum = 0, count = 0;
	scanf("%d", &L);
	for (int i = 2;; i++)
	{
		int prime = 1;
		for (int j = 2; j * j < i + 1; j++)
		{
			if (i % j == 0)
			{
				prime = 0;
			}
		}
		if (prime == 1)
		{
			if (sum + i <= L)
			{
				sum += i;
				count++;
				printf("%d\n", i);
			}
			else
			{
				break;
			}
		}
	}
	printf("%d", count);
	return 0;
}