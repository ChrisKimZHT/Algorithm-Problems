#include <stdio.h>

int main(void)
{
	int n, x, count = 0, num, digit;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		num = i;
		while (num > 9)
		{
			digit = num % 10;
			if (digit == x)
			{
				count++;
			}
			num /= 10;
		}
		if (num == x)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}