#include <stdio.h>

long fact(int n);

int main(void)
{
	int m, n;
	long ans;
	scanf("%d%d", &m, &n);
	ans = fact(n) / (fact(m) * fact(n - m));
	printf("result = %ld", ans);
	return 0;
}

long fact(int n)
{
	long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}