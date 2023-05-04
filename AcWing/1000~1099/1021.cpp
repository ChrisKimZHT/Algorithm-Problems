#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> val(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    vector<vector<int>> dp(n + 10, vector<int>(m + 10));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; j - val[i] * k >= 0; k++)
                dp[i][j] += dp[i - 1][j - val[i] * k];
    cout << dp[n][m] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}