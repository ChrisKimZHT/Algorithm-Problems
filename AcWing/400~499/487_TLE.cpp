#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXM = 80, MAXN = 1e4 + 10;
int N, m;
int v[MAXM], w[MAXM];
int dp[MAXM][MAXN];

int h[MAXM], e[MAXM], ne[MAXM], idx;

void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

void dfs(int now)
{
    for (int i = v[now]; i <= N; i++)
        dp[now][i] = w[now];
    for (int i = h[now]; i != -1; i = ne[i])
    {
        int nxt = e[i];
        dfs(nxt);
        for (int j = N; j >= v[now]; j--)
            for (int k = 0; k <= j - v[now]; k++)
                dp[now][j] = max(dp[now][j], dp[now][j - k] + dp[nxt][k]);
    }
}

void solve()
{
    cin >> N >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
        int t;
        cin >> t;
        add(t, i);
    }
    dfs(0);
    cout << dp[0][N] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof(h));
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}