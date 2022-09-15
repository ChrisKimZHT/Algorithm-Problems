#include <stdio.h>

int main(void)
{
	int x, y, z, t;
	char X, Y, Z;
	scanf("%d%d%d", &x, &y, &z);
	getchar();
	scanf("%c%c%c", &X, &Y, &Z);
	if (x > y)
	{
		t = x;
		x = y;
		y = t;
	}
	if (y > z)
	{
		t = y;
		y = z;
		z = t;
	}
	if (x > y)
	{
		t = x;
		x = y;
		y = t;
	}
	if (X == 'A')
	{
		printf("%d ", x);
	}
	else if (X == 'B')
	{
		printf("%d ", y);
	}
	else if (X == 'C')
	{
		printf("%d ", z);
	}
	if (Y == 'A')
	{
		printf("%d ", x);
	}
	else if (Y == 'B')
	{
		printf("%d ", y);
	}
	else if (Y == 'C')
	{
		printf("%d ", z);
	}
	if (Z == 'A')
	{
		printf("%d\n", x);
	}
	else if (Z == 'B')
	{
		printf("%d\n", y);
	}
	else if (Z == 'C')
	{
		printf("%d\n", z);
	}
	return 0;
}