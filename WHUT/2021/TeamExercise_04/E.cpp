#include <bits/stdc++.h>
#define MOD 1000003

using namespace std;

long long frac_res[1000010];

void frac_init()
{
	frac_res[0] = 1;
	frac_res[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		frac_res[i] = frac_res[i - 1] * i % MOD;
	}
}

long long fastpow(long long a, long long b)
{
	a %= MOD;
	long long ans = 1;
	while (b)
	{
		if (b % 2 == 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

long long comb(int n, int k)
{
	long long ans = frac_res[n];
	ans *= fastpow(frac_res[k], MOD - 2) % MOD;
	ans %= MOD;
	ans *= fastpow(frac_res[n - k], MOD - 2) % MOD;
	ans %= MOD;
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	frac_init();
	int T;
	cin >> T;
	for (int cse = 1; cse <= T; cse++)
	{
		int n, k;
		cin >> n >> k;
		cout << "Case " << cse << ": " << comb(n, k) << endl;
	}
	return 0;
}