#include <stdio.h>
#include <math.h>

int main(void)
{
	int count, n = 1, i;
	double ans;
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		ans += pow(-1, i) * 1.0 / n;
		n += 3;
	}
	printf("sum = %.3lf", ans);
	return 0;
}