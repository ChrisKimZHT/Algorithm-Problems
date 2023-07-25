#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXN = 1010, MOD = 1e9 + 7;
int N, V;
int v[MAXN], w[MAXN];
int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];

void solve()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 0; i <= V; i++)
    {
        cnt[0][i] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            cnt[i][j] = cnt[i - 1][j] % MOD;
            if (j >= v[i])
            {
                if (dp[i][j] < dp[i - 1][j - v[i]] + w[i])
                {
                    dp[i][j] = dp[i - 1][j - v[i]] + w[i];
                    cnt[i][j] = cnt[i - 1][j - v[i]] % MOD;
                }
                else if (dp[i][j] == dp[i - 1][j - v[i]] + w[i])
                {
                    cnt[i][j] = cnt[i][j] + cnt[i - 1][j - v[i]] % MOD;
                }
            }
        }
    }
    cout << cnt[N][V] << endl;
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