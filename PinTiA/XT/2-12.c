#include <stdio.h>

int main(void)
{
	int lower, upper, outf;
	double outc;
	scanf("%d%d", &lower, &upper);
	if (upper < lower || upper > 100 || lower > 100 || upper <= 0 || lower <= 0)
		printf("Invalid.\n");
	else
	{
		printf("fahr celsius\n");
		outf = lower;
		while (outf <= upper)
		{
			outc = 5.0 * (outf - 32) / 9;
			printf("%d%6.1lf\n", outf, outc);
			outf += 2;
		}
	}
	return 0;
}