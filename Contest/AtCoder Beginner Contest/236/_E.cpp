#include <bits/stdc++.h>
#define SIZE 100010
#define esp 1e-4

using namespace std;

int N;
int A[SIZE];

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	double l1 = 1, r1 = 1e9;
	while (r1 - l1 > esp)
	{
		double mid = (l1 + r1) / 2;
		double f[SIZE], g[SIZE];
		f[0] = g[0] = 0;
		for (int i = 1; i <= N; i++)
		{
			f[i] = max(f[i - 1], g[i - 1]) + A[i] - mid;
			g[i] = f[i - 1];
		}
		if (max(f[N], g[N]) >= 0)
		{
			l1 = mid;
		}
		else
		{
			r1 = mid;
		}
	}
	cout << l1 << endl;
	int l2 = 1, r2 = 1e9;
	while (l2 < r2)
	{
		int mid = (l2 + r2 + 1) / 2;
		int f[SIZE], g[SIZE];
		f[0] = g[0] = 0;
		for (int i = 1; i <= N; i++)
		{
			f[i] = max(f[i - 1], g[i - 1]) + ((A[i] >= mid) ? 1 : -1);
			g[i] = f[i - 1];
		}
		if (max(f[N], g[N]) > 0)
		{
			l2 = mid;
		}
		else
		{
			r2 = mid - 1;
		}
	}
	cout << l2 << endl;
	return 0;
}