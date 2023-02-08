#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		long long max = m * n;
		long long ans = 0;
		int beside2, beside3, beside4;
		if (n % 2 == 0 || m % 2 == 0)
		{
			beside4 = (n - 2) * (m - 2) / 2;
			beside3 = n + m - 4;
			beside2 = 2;
			ans = 4 * (max + (max - beside4 + 1)) * beside4 / 2 +
				  3 * ((max - beside4) + (max - beside4 - beside3 + 1)) * beside3 / 2 +
				  2 * ((max - beside4 - beside3) + (max - beside4 - beside3 - beside2 + 1)) * beside2 / 2;
		}
		else if (n % 2 != 0 && m % 2 != 0)
		{
			long long anstmp1 = 0, anstmp2 = 0;
			beside4 = (n - 2) * (m - 2) / 2 + 1;
			beside3 = 2 * (n / 2 + m / 2) - 4;
			beside2 = 4;
			anstmp1 = 4 * (max + (max - beside4 + 1)) * beside4 / 2 +
					  3 * ((max - beside4) + (max - beside4 - beside3 + 1)) * beside3 / 2 +
					  2 * ((max - beside4 - beside3) + (max - beside4 - beside3 - beside2 + 1)) * beside2 / 2;
			beside4 = (n - 2) * (m - 2) / 2;
			beside3 = 2 * (n / 2 + m / 2);
			beside2 = 0;
			anstmp2 = 4 * (max + (max - beside4 + 1)) * beside4 / 2 +
					  3 * ((max - beside4) + (max - beside4 - beside3 + 1)) * beside3 / 2 +
					  2 * ((max - beside4 - beside3) + (max - beside4 - beside3 - beside2 + 1)) * beside2 / 2;
			ans = anstmp1 > anstmp2 ? anstmp1 : anstmp2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}