#include <stdio.h>

int main(void)
{
	int n, curr, last = -10, maxconn = 0, conn = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &curr);
		if (last + 1 == curr)
		{
			conn++;
		}
		else
		{
			conn = 1;
		}
		if (conn > maxconn)
		{
			maxconn = conn;
		}
		last = curr;
	}
	printf("%d", maxconn);
	return 0;
}