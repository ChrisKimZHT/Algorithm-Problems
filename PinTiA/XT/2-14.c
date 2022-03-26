#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count, n = 1, i;
	double ans;
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		ans += 1.0 / n;
		n += 2;
	}
	printf("sum = %lf", ans);
	return 0;
}