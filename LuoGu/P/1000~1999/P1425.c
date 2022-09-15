#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	e = c - a;
	f = d - b;
	if (f < 0)
	{
		f += 60;
		e--;
	}
	printf("%d %d", e, f);
	return 0;
}