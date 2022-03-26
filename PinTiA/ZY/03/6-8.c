#include <stdio.h>
#include <math.h>

double funcos(double e, double x);

int main()
{
	double e, x;

	scanf("%lf %lf", &e, &x);
	printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

	return 0;
}

/* 你的代码将被嵌在这里 */
double funcos(double e, double x)
{
	double ans = 0;
	for (int i = 0;; i += 2)
	{
		double temp = pow(x, i);
		for (int j = 2; j <= i; j++)
		{
			temp /= j;
		}
		ans += pow(-1, i / 2) * temp;
		if (temp < e)
			break;
	}
	return ans;
}