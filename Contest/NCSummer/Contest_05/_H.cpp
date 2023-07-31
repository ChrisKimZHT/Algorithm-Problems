#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 210;
int f[MAXN][MAXN][MAXN];
int a[MAXN], b[MAXN], s[MAXN];
int dp[MAXN][2];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> s[max(1, min(0, n - m) + i)];
    m = min(m, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = 0; k <= 200; k++)
            {
                f[i][j][k] = f[i][j - 1][k];
                if (k - a[j] >= 0)
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - a[j]] + b[j]);
            }
        }
    }
    int p = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                dp[k][p] = max(dp[k][p], dp[j][p ^ 1] + f[j + 1][k][s[i]]);
        p ^= 1;
        for (int j = 0; j <= 200; j++)
            dp[j][p] = 0;
    }
    cout << dp[n][p ^ 1] << endl;
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