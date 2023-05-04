#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> val(n + 10);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        mx = max(mx, val[i]);
    }
    sort(val.begin() + 1, val.begin() + 1 + n);
    vector<vector<int>> dp(n + 10, vector<int>(mx + 10));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= mx; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= val[i])
                dp[i][j] += dp[i][j - val[i]];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (dp[n][val[i]] == 1)
            cnt++;
    cout << cnt << endl;
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