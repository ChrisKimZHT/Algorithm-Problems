#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool numum(int);
void generprime(int);

int list[10000010];

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (b > 10000000)
	{
		b = 10000000;
	}
	generprime(b);
	for (int i = a; i <= b; i++)
	{
		if (list[i] && numum(i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

bool numum(int num)
{
	int numcopy = num, numrev = 0;
	while (numcopy != 0)
	{
		numrev = numrev * 10 + numcopy % 10;
		numcopy /= 10;
	}
	if (num == numrev)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void generprime(int b)
{
	memset(list, true, sizeof(list));
	list[1] = false;
	for (int i = 2; i < b; i++)
	{
		for (int j = 2; j <= b / i; j++)
		{
			if (list[i])
			{
				list[i * j] = false;
			}
		}
	}
}