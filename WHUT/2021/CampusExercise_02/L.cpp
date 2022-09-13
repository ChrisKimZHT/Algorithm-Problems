#include <bits/stdc++.h>
#define SIZE 200010
#define MOD 1000000007

using namespace std;

long long presum_dist[SIZE];
long long cnt[SIZE];
long long presum_cnt[SIZE];
long long presum_mult[SIZE];

int main(void)
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= n; i++)
	{
		cin >> presum_dist[i];
		presum_dist[i] += presum_dist[i - 1];
		presum_dist[i] %= MOD;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> cnt[i];
		presum_cnt[i] = presum_cnt[i - 1] + cnt[i];
		presum_cnt[i] %= MOD;
		presum_mult[i] = presum_mult[i - 1] + presum_dist[i] % MOD * cnt[i] % MOD;
		presum_mult[i] %= MOD;
	}
	while (m--)
	{
		long long x, l, r;
		cin >> x >> l >> r;
		long long ans = 0;
		if (x <= l)
		{
			ans = (presum_mult[r] - presum_mult[l - 1] + MOD) % MOD - presum_dist[x] * (presum_cnt[r] - presum_cnt[l - 1] + MOD) % MOD;
		}
		else if (x >= r)
		{
			ans = presum_dist[x] * (presum_cnt[r] - presum_cnt[l - 1] + MOD) % MOD - (presum_mult[r] - presum_mult[l - 1] + MOD) % MOD;
		}
		else
		{
			ans = presum_dist[x] * (presum_cnt[x] - presum_cnt[l - 1] + MOD) % MOD - (presum_mult[x] - presum_mult[l - 1] + MOD) % MOD + (presum_mult[r] - presum_mult[x - 1] + MOD) % MOD - presum_dist[x] * (presum_cnt[r] - presum_cnt[x - 1] + MOD) % MOD;
			ans %= MOD;
		}
		cout << (ans + MOD) % MOD << endl;
	}
	return 0;
}