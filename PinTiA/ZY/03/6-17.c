#include <stdio.h>
#include <math.h>

int search(int n);

int main()
{
	int number;

	scanf("%d", &number);
	printf("count=%d\n", search(number));

	return 0;
}

/* 你的代码将被嵌在这里 */
int search(int n)
{
	int count = 0;
	for (int i = 101; i <= n; i++)
	{
		for (int j = 1; j < 40; j++)
		{
			if (j * j == i)
			{
				if (i % 10 == (i / 10) % 10 || i % 10 == (i / 100) % 10 || (i / 10) % 10 == (i / 100) % 10)
					count++;
			}
		}
	}
	return count;
}