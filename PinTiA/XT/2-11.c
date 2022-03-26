#include <stdio.h>
#include <math.h>

int main(void)
{
	double in, out;
	scanf("%lf", &in);
	if (in >= 0)
		out = sqrt(in);
	else
		out = pow(in + 1, 2) + 2 * in + 1 / in;
	printf("f(%.2lf) = %.2lf", in, out);
	return 0;
}