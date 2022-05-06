#include <stdio.h>

int main(void)
{
	int n, ans;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		ans += i;
	}
	printf("%d", ans);
	return 0;
}