#include <stdio.h>

int main(void)
{
	char c[9], y;
	int x, sum = 0, ans;
	scanf("%c%*c%c%c%c%*c%c%c%c%c%c%*c", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7], &c[8]);
	scanf("%c", &y);
	if (y == 'X')
	{
		x = 10;
	}
	else
	{
		x = y - '0';
	}
	for (int i = 0; i < 9; i++)
	{
		c[i] -= '0';
		sum += c[i] * (i + 1);
	}
	ans = sum % 11;
	if (x == ans)
	{
		printf("Right");
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			printf("%d", c[i]);
			if (i == 0 || i == 3 || i == 8)
			{
				printf("-");
			}
		}
		if (ans == 10)
		{
			printf("X");
		}
		else
		{
			printf("%d", ans);
		}
	}
	return 0;
}