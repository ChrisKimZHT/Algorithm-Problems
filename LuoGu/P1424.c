#include <stdio.h>

int main(void)
{
	int x, n, ans = 0;
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; i++)
	{
		if (x >= 1 && x <= 5)
		{
			ans += 250;
		}
		x++;
		if (x == 8)
		{
			x = 1;
		}
	}
	printf("%d", ans);
}