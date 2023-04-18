#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> mat(R + 10, vector<int>(C + 10));
    vector<vector<int>> dp(R + 10, vector<int>(C + 10));
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mat[i][j];
    cout << dp[R][C] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}