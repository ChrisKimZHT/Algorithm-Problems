#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXM = 30, MAXN = 3e4 + 10;
int N, m;
int v[MAXM], p[MAXM], w[MAXM];
int dp[MAXM][MAXN];

void solve()
{
    cin >> N >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> p[i];
        w[i] = v[i] * p[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] > 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[m][N] << endl;
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