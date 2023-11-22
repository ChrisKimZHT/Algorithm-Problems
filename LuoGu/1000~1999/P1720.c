#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	double ans = (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
	printf("%.2lf", ans);
	return 0;
}