#include <stdio.h>

int main(void)
{
	int cash = 0, deposit = 0, budget[13];
	for (int i = 1; i <= 12; i++)
	{
		scanf("%d", &budget[i]);
	}
	for (int i = 1; i <= 12; i++)
	{
		cash += 300;
		cash -= budget[i];
		if (cash < 0)
		{
			printf("-%d", i);
			return 0;
		}
		if (cash / 100 > 0)
		{
			deposit += cash / 100 * 100;
			cash -= cash / 100 * 100;
		}
	}
	printf("%.0lf", 1.0 * cash + 1.2 * deposit);
	return 0;
}