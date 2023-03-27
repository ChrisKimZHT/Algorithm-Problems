#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 110;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN];

void solve()
{
    int N;
    cin >> N;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = dp[1][0] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + mat[i][j];
    cout << dp[N][N] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}