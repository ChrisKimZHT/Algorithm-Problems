#include <stdio.h>

int main(void)
{
	int N;
	double ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		ans += 1.0 / i;
	}
	printf("sum = %lf\n", ans);
	return 0;
}