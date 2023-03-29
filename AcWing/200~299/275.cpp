#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 55;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

void solve()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    int t = mat[i][j];
                    if (i != k || j != l)
                        t += mat[k][l];
                    dp[i][j][k][l] = max({dp[i][j][k][l],
                                          dp[i - 1][j][k - 1][l] + t,
                                          dp[i - 1][j][k][l - 1] + t,
                                          dp[i][j - 1][k - 1][l] + t,
                                          dp[i][j - 1][k][l - 1] + t});
                }
            }
        }
    }
    cout << dp[m][n][m][n] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}