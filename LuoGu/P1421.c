#include <stdio.h>

int main(void)
{
	int a, b, x, ans;
	scanf("%d%d", &a, &b);
	x = 10 * a + b;
	ans = x / 19;
	printf("%d", ans);
	return 0;
}