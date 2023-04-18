#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 15;
int mat[MAXN][MAXN];
int dp[2 * MAXN][MAXN][MAXN];

void solve()
{
    int N;
    cin >> N;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
        mat[a][b] = c;
    for (int s = 2; s <= 2 * N; s++)
    {
        for (int i = 1; i < s; i++)
        {
            for (int k = 1; k < s; k++)
            {
                int j = s - i, l = s - k;
                int t = mat[i][j];
                if (i != k || j != l)
                    t += mat[k][l];
                dp[s][i][k] = max({dp[s][i][k],
                                   dp[s - 1][i - 1][k - 1] + t,
                                   dp[s - 1][i - 1][k] + t,
                                   dp[s - 1][i][k - 1] + t,
                                   dp[s - 1][i][k] + t});
            }
        }
    }
    cout << dp[2 * N][N][N] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}