#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 310, MAXM = 15, MOD = 1e9 + 7;
int n, t, k, m;
int a[MAXN], pa[MAXN];
int dp[MAXN][MAXM][1 << MAXM];

void solve()
{
    cin >> n >> t >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a[t]++;
    }
    for (int i = 1; i <= t; i++)
        pa[i] = pa[i - 1] + a[i];
    int mask = (1 << k) - 1;
    dp[0][0][0] = 1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= pa[i]; j++)
        {
            for (int p = 0; p < (1 << k); p++)
            {
                int cur = (p << 1) & mask;
                dp[i][j][cur] += dp[i - 1][j][p];
                dp[i][j][cur] %= MOD;
            }
        }
        for (int j = 0; j <= pa[i]; j++)
        {
            for (int p = 0; p < (1 << k); p++)
            {
                int cur = ((p << 1) & mask) | 1;
                if (__builtin_popcount(cur) > m)
                    continue;
                dp[i][j + 1][cur] += dp[i - 1][j][p] * (pa[i] - j) % MOD;
                dp[i][j + 1][cur] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << k); i++)
        ans = (ans + dp[t][n][i]) % MOD;
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