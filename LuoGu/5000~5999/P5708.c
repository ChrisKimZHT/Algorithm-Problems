#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c, p, ans;
	scanf("%lf%lf%lf", &a, &b, &c);
	p = 0.5 * (a + b + c);
	ans = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("%.1lf", ans);
	return 0;
}