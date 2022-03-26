#include <stdio.h>

int main(void)
{
	int n, max = -1, min = 11, sum = 0;
	double ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		sum += temp;
		if (temp > max)
		{
			max = temp;
		}
		if (temp < min)
		{
			min = temp;
		}
	}
	ans = 1.0 * (sum - max - min) / (n - 2);
	printf("%.2lf", ans);
	return 0;
}