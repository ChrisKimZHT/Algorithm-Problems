#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MOD = 1919810;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<string> b(m + 10);
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector dp(n + 10, vector<int>(m + 10));
    for (int i = 0; i <= m; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = dp[j][i - 1];
            if (a[j] == b[i])
                dp[j][i] = (dp[j][i] + dp[j - 1][i - 1]) % MOD;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}