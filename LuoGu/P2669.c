#include <stdio.h>

int main(void)
{
	int k;
	int n = 1;
	int day = 1;
	int coin = 0;
	scanf("%d", &k);
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			coin += n;
			day++;
			if (day > k)
				break;
		}
		if (day > k)
			break;
		n++;
	}
	printf("%d", coin);
	return 0;
}