#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10), dp(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        dp[i] = dp[i + 1] + 1;
        if (i + a[i] <= n)
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
    }
    cout << dp[1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}