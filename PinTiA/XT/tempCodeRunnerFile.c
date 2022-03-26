#include <stdio.h>

int main(void)
{
	unsigned long long up = 2, down = 1, N;
	double a, ans = 0;
	scanf("%ull", &N);
	while (N--)
	{
		a = 1.0 * up / down;
		ans += a;
		unsigned long long temp = up;
		up += down;
		down = temp;
	}
	printf("%.2lf", ans);
	return 0;
}