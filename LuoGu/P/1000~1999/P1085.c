#include <stdio.h>

int main(void)
{
	int a, b, sum, day, max = 0;
	for (int i = 1; i <= 7; i++)
	{
		scanf("%d%d", &a, &b);
		sum = a + b;
		if (max < sum)
		{
			max = sum;
			day = i;
		}
	}
	printf("%d", day);
	return 0;
}