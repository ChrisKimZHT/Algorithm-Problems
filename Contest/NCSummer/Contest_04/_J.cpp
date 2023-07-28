#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXN = 5050;
int n, m;
int dp[2 * MAXN], sum[2 * MAXN];

void solve()
{
    cin >> n >> m;
    for (int i = m; i >= -m; i--)
    {
        dp[i + m] = 1;
        sum[i + m] = sum[i + 1 + m] + 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = m; j >= -m; j--)
        {
            if (j >= 0)
                dp[j + m] = sum[j];
            else
                dp[j + m] = sum[m - j];
        }
        for (int j = m; j >= -m; j--)
            sum[j + m] = (sum[j + m + 1] + dp[j + m]) % MOD;
        // for (int j = m; j >= -m; j--)
        //     cout << sum[j + m] - sum[j + m + 1] << " \n"[j == -m];
    }
    cout << sum[0] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}