#include <stdio.h>

double fn(double x, int n);

int main()
{
	double x;
	int n;

	scanf("%lf %d", &x, &n);
	printf("%.2f\n", fn(x, n));

	return 0;
}

/* 你的代码将被嵌在这里 */
double fn(double x, int n)
{
#include <math.h>
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += pow(-1, i - 1) * pow(x, i);
	}
	return ans;
}