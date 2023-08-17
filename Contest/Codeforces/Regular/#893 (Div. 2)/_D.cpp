#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void calc(vector<vector<vector<int>>> &dp, string &s, int k)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int m = 0; m < 2; m++)
            {
                int cost = (s[i] - '0') != m;
                if (j + cost <= k)
                {
                    dp[i + 1][j + cost][m] = max(dp[i + 1][j + cost][m], dp[i][j][m] + 1);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int m = 0; m < 2; m++)
            {
                if (i - 1 >= 0)
                    dp[i][j][m] = max(dp[i][j][m], dp[i - 1][j][m]);
                if (j - 1 >= 0)
                    dp[i][j][m] = max(dp[i][j][m], dp[i][j - 1][m]);
            }
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<vector<int>>> dp1(n + 10, vector<vector<int>>(k + 10, vector<int>(2)));
    vector<vector<vector<int>>> dp2(n + 10, vector<vector<int>>(k + 10, vector<int>(2)));
    calc(dp1, s, k);
    reverse(s.begin(), s.end());
    calc(dp2, s, k);
    vector<int> l(n + 10, INT32_MIN);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int m = 0; m < 2; m++)
            {
                int a = dp1[i][j][m];
                int b = dp2[n - i][k - j][m ^ 1];
                if (m) // a=1, b=0
                    l[b] = max(l[b], a);
                else // a=0, b=1
                    l[a] = max(l[a], b);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
        l[i] = max(l[i], l[i + 1]);
    vector<int> ans(n + 10);
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans[j] = max(ans[j], i * j + l[i]);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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