#include <stdio.h>

int main(void)
{
	int n, a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int min = 1001;
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	printf("%d", min);
	return 0;
}