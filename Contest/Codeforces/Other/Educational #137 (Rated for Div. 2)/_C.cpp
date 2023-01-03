#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> st(n + 1);
    st[0] = true;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            st[i + 1] = true;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pair<int, int>> dp(n + 1); // first-no secend-yes
    for (int i = 1; i <= n; i++)
    {
        dp[i].first = max(dp[i - 1].first, dp[i - 1].second) + (st[i] ? a[i] : 0);
        dp[i].second = st[i] ? dp[i - 1].second + a[i - 1] : dp[i].first;
        // cout << dp[i].first << ' ' << dp[i].second << endl;
    }
    cout << max(dp[n].first, dp[n].second) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}