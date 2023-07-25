#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXN = 110;
int N, V;
int v[MAXN], w[MAXN];
int h[MAXN], e[MAXN], ne[MAXN];
int pos, root;
int dp[MAXN][MAXN];

void add(int x, int y)
{
    e[pos] = y;
    ne[pos] = h[x];
    h[x] = pos++;
}

void dfs(int now)
{
    for (int i = v[now]; i <= V; i++)
        dp[now][i] = w[now];
    for (int i = h[now]; i != -1; i = ne[i])
    {
        int nxt = e[i];
        dfs(nxt);
        for (int j = V; j >= v[now]; j--)
            for (int k = 0; k <= j - v[now]; k++)
                dp[now][j] = max(dp[now][j], dp[now][j - k] + dp[nxt][k]);
    }
}

void solve()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i];
        int f;
        cin >> f;
        if (f == -1)
            root = i;
        else
            add(f, i);
    }
    dfs(root);
    cout << dp[root][V] << endl;
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