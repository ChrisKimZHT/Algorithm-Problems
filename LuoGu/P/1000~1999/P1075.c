#include <stdio.h>

int main(void)
{
	int n, ans, a = 2;
	scanf("%d", &n);
	while (1)
	{
		if (n % a == 0)
		{
			ans = n / a;
			break;
		}
		a++;
	}
	printf("%d", ans);
	return 0;
}