#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	unsigned long long a[200010], sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		unsigned long long x, y, hicoin = 0, locoin = 0;
		cin >> x >> y;
		int hipos = lower_bound(a, a + n, x) - a, lopos;
		if (hipos != n)
		{
			if (sum - a[hipos] >= y)
			{
				cout << '0' << endl;
				continue;
			}
			else
			{
				hicoin = y - (sum - a[hipos]);
				if (hipos)
				{
					lopos = hipos - 1;
					if (sum - a[lopos] >= y)
					{
						locoin = x - a[lopos];
					}
					else
					{
						locoin = x + y - sum;
					}
					cout << min(hicoin, locoin) << endl;
					continue;
				}
				else
				{
					cout << hicoin << endl;
					continue;
				}
			}
		}
		else
		{
			if (sum - a[n - 1] < y)
			{
				cout << x + y - sum << endl;
				continue;
			}
			else
			{
				cout << x - a[n - 1] << endl;
				continue;
			}
		}
	}
	return 0;
}