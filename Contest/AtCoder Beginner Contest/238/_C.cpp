#include <bits/stdc++.h>
#define MOD 998244353
#define INV_2 499122177

using namespace std;

long long pow_10(int x)
{
	long long ans = 1;
	for (int i = 0; i < x; i++)
		ans *= 10;
	return ans;
}

int main(void)
{
	long long N;
	cin >> N;
	long long t = N;
	int num_digit = 0;
	while (t)
	{
		t /= 10;
		num_digit++;
	}
	long long x = (N - pow_10(num_digit - 1) + 1) % MOD;
	long long ans = x;
	ans *= x + 1;
	ans %= MOD;
	ans *= INV_2;
	ans %= MOD;
	for (int i = num_digit - 1; i > 0; i--)
	{
		long long y = (pow_10(i) - pow_10(i - 1)) % MOD;
		long long tmp = y;
		tmp *= y + 1;
		tmp %= MOD;
		tmp *= INV_2;
		tmp %= MOD;
		ans += tmp;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}