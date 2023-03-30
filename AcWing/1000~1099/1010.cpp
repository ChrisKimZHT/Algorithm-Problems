#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    vector<int> a{0};
    int t;
    while (cin >> t)
        a.push_back(t);
    vector<int> dp(a.size()), dp2(a.size());
    for (int i = 1; i < a.size(); i++)
    {
        dp[i] = dp2[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] >= a[i])
                dp[i] = max(dp[i], dp[j] + 1);
            else
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i < a.size(); i++)
    {
        ans = max(ans, dp[i]);
        cnt = max(cnt, dp2[i]);
    }
    cout << ans << endl
         << cnt << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}