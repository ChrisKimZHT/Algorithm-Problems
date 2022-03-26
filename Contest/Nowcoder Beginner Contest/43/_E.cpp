#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main(void)
{
	int cnt[10];
	for (int i = 1; i <= 9; i++)
	{
		cin >> cnt[i];
	}
	long long dp[10][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 9; i++)
	{
		int mod_1 = (0 * i) % 3, mod_2 = (1 * i) % 3, mod_3 = (2 * i) % 3;
		int cnt_mod_1 = cnt[i] / 3 + 1, cnt_mod_2 = (cnt[i] + 1) / 3, cnt_mod_3 = (cnt[i] + 2) / 3;
		for (int j = 0; j < 3; j++)
		{
			dp[i][(j + mod_1) % 3] += dp[i - 1][j] * cnt_mod_1;
			dp[i][(j + mod_2) % 3] += dp[i - 1][j] * cnt_mod_2;
			dp[i][(j + mod_3) % 3] += dp[i - 1][j] * cnt_mod_3;
			dp[i][(j + mod_1) % 3] %= MOD;
			dp[i][(j + mod_2) % 3] %= MOD;
			dp[i][(j + mod_3) % 3] %= MOD;
		}
	}
	cout << dp[9][0] << endl;
	return 0;
}