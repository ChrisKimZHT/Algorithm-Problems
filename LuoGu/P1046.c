#include <stdio.h>

int main(void)
{
	int h[10], r, count = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &h[i]);
	}
	scanf("%d", &r);
	for (int i = 0; i < 10; i++)
	{
		if (r + 30 >= h[i])
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}