#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;
unsigned long long dp[1000010][10]{};

int main(void)
{
    int N;
    cin >> N;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] %= MOD;
        for (int j = 2; j <= 8; j++)
        {
            dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= MOD;
        }
        dp[i][9] = dp[i - 1][9] + dp[i - 1][8];
        dp[i][9] %= MOD;
    }
    long long ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        ans += dp[N][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}