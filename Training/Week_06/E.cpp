#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, double y);

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		double Y;
		scanf("%lf", &Y);
		double l = 0, r = 100;
		double eps = 1e-6;
		while (r - l > eps)
		{
			double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			if (f(m1, Y) > f(m2, Y))
				l = m1;
			else
				r = m2;
		}
		printf("%.4lf\n", f(l, Y));
	}
	system("pause");
	return 0;
}

double f(double x, double y)
{
	double ans = 6.0 * pow(x, 7) + 8.0 * pow(x, 6) + 7.0 * pow(x, 3) + 5.0 * pow(x, 2) - y * x;
	return ans;
}