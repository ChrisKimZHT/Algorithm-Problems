#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 10;
long long dp[MAXN][4];

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), ' ');
    // vector<vector<long long>> dp(s.size(), vector<long long>(4));
    dp[0][0] = dp[1][0] = dp[1][1] = 1LL;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = 1LL;
        for (int j = 1; j <= 3; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            if (i - 2 >= 0 &&
                j - 1 >= 0 &&
                s[i] == s[i - 1])
                dp[i][j] -= dp[i - 2][j - 1];
            if (i - 3 >= 0 &&
                j - 2 >= 0 && s[i] == s[i - 2] &&
                s[i] != s[i - 1])
                dp[i][j] -= dp[i - 3][j - 2];
            if (i - 4 >= 0 &&
                j - 3 >= 0 &&
                s[i] == s[i - 3] &&
                s[i] != s[i - 1] &&
                s[i] != s[i - 2])
                dp[i][j] -= dp[i - 4][j - 3];
        }
    }
    // cout << accumulate(dp[n].begin(), dp[n].end(), 0LL) << endl;
    cout << accumulate(dp[n], dp[n] + 4, 0LL) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}