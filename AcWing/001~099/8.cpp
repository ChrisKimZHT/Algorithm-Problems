#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXN = 1010, MAXM = 110;
int v[MAXN], m[MAXN], w[MAXN];
int dp[MAXM][MAXM];

void solve()
{
    int N, V, M;
    cin >> N >> V >> M;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> m[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = V; j >= 0; j--)
            for (int k = M; k >= 0; k--)
                if (j >= v[i] && k >= m[i])
                    dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + w[i]);
    cout << dp[V][M] << endl;
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