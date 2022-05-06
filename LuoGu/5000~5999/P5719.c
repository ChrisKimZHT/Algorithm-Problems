#include <stdio.h>

int main(void)
{
	int n, k, sum_a = 0, sum_b = 0, count_a = 0, count_b = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			sum_a += i;
			count_a++;
		}
		else
		{
			sum_b += i;
			count_b++;
		}
	}
	printf("%.1lf %.1lf", (double)sum_a / count_a, (double)sum_b / count_b);
	return 0;
}