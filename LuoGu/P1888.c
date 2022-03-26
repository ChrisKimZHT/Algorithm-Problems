#include <stdio.h>

int gcd(int x, int y);

int main(void)
{
	int a, b, c, t;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	int x = gcd(a, c);
	printf("%d/%d", a / x, c / x);
	return 0;
}

int gcd(int x, int y)
{
	int min;
	if (x > y)
	{
		min = y;
	}
	else
	{
		min = x;
	}
	int i;
	for (i = min; i > 0; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			break;
		}
	}
	return i;
}