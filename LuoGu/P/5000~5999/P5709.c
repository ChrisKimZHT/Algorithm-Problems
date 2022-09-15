#include <stdio.h>

int main(void)
{
	int m, t, s, ans;
	scanf("%d%d%d", &m, &t, &s);
	if (t == 0)
		ans = 0;
	else
	{
		ans = m - s / t;
		if (s % t != 0)
			ans--;
		if (ans <= 0)
			ans = 0;
	}
	printf("%d", ans);
	return 0;
}