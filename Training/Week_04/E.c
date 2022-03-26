#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int count, m, n, max, ans, _m, a;
	scanf("%d", &count);
	while (count--)
	{
		ans = 0;
		scanf("%d%d", &n, &m);
		_m = (m >= 30) ? 30 : m;
		for (int j = _m; j >= 0; j--)
		{
			if (pow(2, j) <= n)
			{
				max = j;
				break;
			}
		}
		while (n > 0)
		{
			a = n / pow(2, max);
			ans += a;
			n -= a * pow(2, max);
			max--;
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}