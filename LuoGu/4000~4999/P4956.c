#include <stdio.h>

int main(void)
{
	int n, x, k, a;
	scanf("%d", &n);
	a = n / 364;
	for (int i = 100; i > 0; i--)
	{
		int temp = (a - i) / 3;
		if (a - i > 0 && (a - i) % 3 == 0)
		{
			printf("%d\n%d\n", i, temp);
			break;
		}
	}
	return 0;
}