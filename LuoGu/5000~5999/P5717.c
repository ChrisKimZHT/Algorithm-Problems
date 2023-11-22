#include <stdio.h>

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
	if (a + b <= c)
	{
		printf("Not triangle\n");
	}
	else
	{
		if (a * a + b * b == c * c)
		{
			printf("Right triangle\n");
		}
		else if (a * a + b * b > c * c)
		{
			printf("Acute triangle\n");
		}
		else
		{
			printf("Obtuse triangle\n");
		}
		if (a == b || b == c || a == c)
		{
			printf("Isosceles triangle\n");
		}
		if (a == b && b == c)
		{
			printf("Equilateral triangle\n");
		}
	}
	return 0;
}