/**
 *    author:  tourist
 *    created: 23.01.2022 15:04:46       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

double Solve(vector<double> a)
{
	vector<double> f(2);
	f[0] = 0;
	f[1] = a[0];
	for (int i = 1; i < (int)a.size(); i++)
	{
		vector<double> nf(2);
		nf[0] = f[1];
		nf[1] = max(f[0], f[1]) + a[i];
		swap(f, nf);
	}
	return max(f[0], f[1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	{
		double low = 0, high = 1e9;
		for (int it = 0; it < 100; it++)
		{
			double mid = (low + high) * 0.5;
			vector<double> b(n);
			for (int i = 0; i < n; i++)
			{
				b[i] = a[i] - mid;
			}
			if (Solve(b) >= 0)
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		cout << fixed << setprecision(17) << 0.5 * (low + high) << '\n';
	}
	{
		int low = 0, high = 1e9;
		while (low < high)
		{
			int mid = (low + high + 1) >> 1;
			vector<double> b(n);
			for (int i = 0; i < n; i++)
			{
				b[i] = (a[i] >= mid ? 1 : -1);
			}
			if (Solve(b) > 0.5)
			{
				low = mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		cout << low << '\n';
	}
	return 0;
}
