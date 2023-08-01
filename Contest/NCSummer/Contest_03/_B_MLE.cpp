#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 330;
int dp[2][MAXN][MAXN][MAXN];
int fact[2 * MAXN];

void init_fact(int p)
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 2 * MAXN; i++)
        fact[i] = (fact[i - 1] * i) % p;
}

void solve()
{
    int n, mod;
    cin >> n >> mod;
    init_fact(mod);
    memset(dp, 0, sizeof(dp));
    int ans = fact[2 * n];
    for (int i = 1; i <= n; i++)
    {
        dp[0][n][n][i] = i % mod;
        dp[1][n][n][i] = i % mod;
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i + j == 2 * n)
                continue;
            for (int k = 1; k <= i; k++)
            {
                if (i != n)
                    dp[0][i][j][k] = (dp[0][i][j][k] + (dp[0][i + 1][j][i + 1] - dp[0][i + 1][j][k] + mod) % mod) % mod;
                if (j != n)
                    dp[0][i][j][k] = (dp[0][i][j][k] + dp[1][i][j + 1][j + 1]) % mod;
                ans = (ans + dp[0][i][j][k] * fact[i + j - 1]) % mod;
            }
            for (int k = 1; k <= i; k++)
                dp[0][i][j][k] = (dp[0][i][j][k] + dp[0][i][j][k - 1]) % mod;
            // for (int k = 1; k <= i; k++)
            //     cout << dp[1][i][j][k] << " \n"[k == i];
            for (int k = 1; k <= j; k++)
            {
                if (j != n)
                    dp[1][i][j][k] = (dp[1][i][j][k] + (dp[1][i][j + 1][j + 1] - dp[1][i][j + 1][k] + mod) % mod) % mod;
                if (i != n)
                    dp[1][i][j][k] = (dp[1][i][j][k] + dp[0][i + 1][j][i + 1]) % mod;
                ans = (ans + dp[1][i][j][k] * fact[i + j - 1]) % mod;
            }
            for (int k = 1; k <= j; k++)
                dp[1][i][j][k] = (dp[1][i][j][k] + dp[1][i][j][k - 1]) % mod;
            // for (int k = 1; k <= j; k++)
            //     cout << dp[1][i][j][k] << " \n"[k == j];
        }
    }
    ans = (ans + fact[2 * n] - dp[0][1][0][1] - dp[1][0][1][1] + mod) % mod;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}