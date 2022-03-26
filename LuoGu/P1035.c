#include <stdio.h>

int main(void)
{
	int k, i;
	double S = 0;
	scanf("%d", &k);
	for (i = 1; S <= k; i++)
	{
		S += 1.0 / i;
	}
	printf("%d", i - 1);
	return 0;
}