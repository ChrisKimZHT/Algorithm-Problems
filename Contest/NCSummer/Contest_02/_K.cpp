#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10), b(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 10, vector<int>(3));
    int last = -2;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 1)
        {
            if (i - last == 1)
            {
                dp[i][0] = dp[i - 1][0] + a[i - 1];
                dp[i][1] = max({dp[i - 1][0], dp[i - 1][1]}) + a[i];
                dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i + 1];
            }
            else if (i - last == 2)
            {
                dp[i][0] = max({dp[i - 1][0], dp[i - 1][1]}) + a[i - 1];
                dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i];
                dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i + 1];
            }
            else
            {
                dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i - 1];
                dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i];
                dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i + 1];
            }
            last = i;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}