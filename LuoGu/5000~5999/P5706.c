#include <stdio.h>

int main(void)
{
	int n;
	double t;
	scanf("%lf%d", &t, &n);
	printf("%.3lf\n%d", t / n, n * 2);
	return 0;
}