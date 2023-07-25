#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXN = 1010, MOD = 1e9 + 7;
int N, V;
int v[MAXN], w[MAXN];
int dp[MAXN][MAXN];

void solve()
{
    cin >> N >> V;
    for (int i = N; i >= 1; i--)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    for (int i = N, j = V; i >= 1; i--)
    {
        if (j >= v[i] && dp[i - 1][j - v[i]] + w[i] == dp[i][j])
        {
            cout << N - i + 1 << ' ';
            j -= v[i];
        }
    }
    cout << endl;
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