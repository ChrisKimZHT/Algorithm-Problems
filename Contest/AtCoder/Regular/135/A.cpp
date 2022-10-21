#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

map<long long, long long> m;

long long solve(long long x)
{
	if (m[x])
	{
		return m[x];
	}
	else
	{
		if (x == 2)
		{
			m[x] = 2;
			return 2;
		}
		else if (x == 3)
		{
			m[x] = 3;
			return 3;
		}
		else if (x % 2)
		{
			m[x] = (solve(x / 2) * solve(x / 2 + 1)) % MOD;
			return m[x];
		}
		else
		{
			m[x] = (solve(x / 2) * solve(x / 2)) % MOD;
			return m[x];
		}
	}
}

int main(void)
{
	long long X;
	cin >> X;
	if (X == 1)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << solve(X) << endl;
	}
	return 0;
}