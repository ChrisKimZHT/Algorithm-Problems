#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXN = 20;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN];
int ans[MAXN][MAXN];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = j; k <= m; k++)
            {
                if (dp[i][k] <= dp[i - 1][j] + mat[i][k - j])
                {
                    dp[i][k] = dp[i - 1][j] + mat[i][k - j];
                    ans[i][k] = j;
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    vector<int> t;
    for (int i = n, j = m; i >= 1; j = ans[i][j], i--)
        t.push_back(j - ans[i][j]);
    for (int i = t.size() - 1; i >= 0; i--)
        cout << t.size() - i << ' ' << t[i] << endl;
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