#include <stdio.h>

int main(void)
{
	int N, sgn = 0, ans = 0;
	scanf("%d", &N);
	if (N > 0)
	{
		sgn = 1;
	}
	else if (N < 0)
	{
		N *= -1;
		sgn = -1;
	}
	while (N)
	{
		ans = ans * 10 + N % 10;
		N /= 10;
	}
	printf("%d", ans * sgn);
	return 0;
}