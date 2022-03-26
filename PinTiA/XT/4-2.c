#include <stdio.h>
#include <math.h>

int main(void)
{
	int count = 1;
	double a, ans = 1, x;
	scanf("%lf", &x);
	do
	{
		a = pow(x, count);
		for (int i = 1; i <= count; i++)
		{
			a /= i;
		}
		ans += a;
		count++;
	} while (a > 0.00001);
	printf("%.4lf\n", ans);
	return 0;
}