#include <stdio.h>

int main(void)
{
	int n, max = -1, min = 1001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp > max)
		{
			max = temp;
		}
		if (temp < min)
		{
			min = temp;
		}
	}
	printf("%d", max - min);
	return 0;
}