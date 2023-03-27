#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 15;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

void solve()
{
    int N;
    cin >> N;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
        mat[a][b] = c;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                for (int l = 1; l <= N; l++)
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
    // while (true)
    // {
    //     int a, b, c, d;
    //     cin >> a >> b >> c >> d;
    //     cout << dp[a][b][c][d] << endl;
    // }
    cout << dp[N][N][N][N] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}