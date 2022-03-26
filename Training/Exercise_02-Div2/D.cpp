#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	long long ps[100010];
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &ps[i]);
		ps[i] += ps[i - 1];
	}
	set<long long> power;
	if (k == 1)
	{
		power.insert(1);
	}
	else if (k == -1)
	{
		power.insert(1);
		power.insert(-1);
	}
	else
	{
		for (long long i = 1; abs(i) < (long long)1e14 + 10; i *= k)
			power.insert(i);
	}
	long long cnt = 0;
	map<long long, int> pscnt;
	pscnt[0] = 1;
	for (int r = 1; r <= n; r++)
	{
		for (auto it = power.begin(); it != power.end(); ++it)
		{
			long long l = ps[r] - (*it);
			cnt += pscnt[l];
		}
		pscnt[ps[r]]++;
	}
	cout << cnt << endl;
	return 0;
}