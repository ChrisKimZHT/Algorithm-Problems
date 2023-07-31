#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXN = 5050;
int n, m;
int dp[MAXN][2 * MAXN], suf[MAXN][2 * MAXN];

void solve()
{
    cin >> n >> m;
    for (int i = m; i >= -m; i--)
        dp[1][i + m] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = m; j >= -m; j--)
        {
            if (j >= 0)
            {
                for (int k = m; k >= j - m; k--)
                {
                    dp[i][j + m] = (dp[i][j + m] + dp[i - 1][k + m]) % MOD;
                }
            }
            else
            {
                for (int k = m; k >= -j; k--)
                {
                    dp[i][j + m] = (dp[i][j + m] + dp[i - 1][k + m]) % MOD;
                }
            }
        }
        // for (int j = -m; j <= m; j++)
        //     cout << dp[i][j + m] << " \n"[j == m];
    }
    int ans = 0;
    for (int i = m; i >= -m; i--)
        ans = (ans + dp[n][i + m]) % MOD;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}