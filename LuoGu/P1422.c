#include <stdio.h>

int main(void)
{
	int amount;
	double cost;
	scanf("%d", &amount);
	if (amount <= 150)
	{
		cost = 0.4463 * amount;
	}
	else if (amount > 150 && amount <= 400)
	{
		cost = 0.4463 * 150 + 0.4663 * (amount - 150);
	}
	else
	{
		cost = 0.4463 * 150 + 0.4663 * 250 + 0.5663 * (amount - 400);
	}
	printf("%.1lf", cost);
	return 0;
}