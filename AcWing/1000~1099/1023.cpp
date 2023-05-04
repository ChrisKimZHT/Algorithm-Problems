#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int val[5] = {0, 10, 20, 50, 100};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(10, vector<int>(n + 10));
    dp[0][0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; j - val[i] * k >= 0; k++)
                dp[i][j] += dp[i - 1][j - val[i] * k];
    cout << dp[4][n] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}