#include <stdio.h>

int main()
{
	double in, out;
	scanf("%lf", &in);
	if (in == 0)
		out = 0;
	else
		out = 1.0 / in;
	printf("f(%.1lf) = %.1lf\n", in, out);
	return 0;
}