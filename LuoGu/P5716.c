#include <stdio.h>

int main(void)
{
	int y, m;
	int d1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int d2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d%d", &y, &m);
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{
		printf("%d", d2[m - 1]);
	}
	else
	{
		printf("%d", d1[m - 1]);
	}
	return 0;
}