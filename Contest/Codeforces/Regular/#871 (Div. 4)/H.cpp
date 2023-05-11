#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 10, vector<int>(1 << 6));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dp[i][a] = (dp[i][a] + 1) % MOD;
        for (int j = 0; j < 1 << 6; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][j & a] = (dp[i][j & a] + dp[i - 1][j]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << 6; i++)
        if (__builtin_popcount(i) == k)
            ans = (ans + dp[n][i]) % MOD;
    cout << ans << endl;
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