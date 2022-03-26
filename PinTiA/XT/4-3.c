#include <stdio.h>

int main(void)
{
	double up = 2, down = 1, N;
	double a, ans = 0;
	scanf("%lf", &N);
	while (N--)
	{
		a = 1.0 * up / down;
		ans += a;
		double temp = up;
		up += down;
		down = temp;
	}
	printf("%.2lf", ans);
	return 0;
}