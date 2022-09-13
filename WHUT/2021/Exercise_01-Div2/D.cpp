#include <bits/stdc++.h>

using namespace std;

long long f(long long k, long long n)
{
	if (n <= k)
	{
		return (1 + n) * n / 2;
	}
	else
	{
		return k * k - (1 + (2 * k - 1 - n)) * (2 * k - 1 - n) / 2;
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long k, x;
		cin >> k >> x;
		long long l = 1, r = 2 * k - 1;
		while (l < r)
		{
			long long mid = (l + r) / 2;
			if (f(k, mid) >= x)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		cout << r << endl;
	}
	return 0;
}