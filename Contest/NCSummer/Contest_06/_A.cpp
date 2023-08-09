#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 3e3 + 10;
int n;
int a[MAXN], cost[MAXN];
int fa[MAXN << 1];
int val[MAXN << 1], siz[MAXN << 1];
vector<int> krus[MAXN << 1];
int dp[MAXN << 1][MAXN];

void init()
{
    for (int i = 0; i < (MAXN << 1); i++)
        fa[i] = i;
}

int find(int x)
{
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

void dfs(int now)
{
    if (now <= n)
    {
        siz[now] = 1;
        dp[now][a[now]] = 0;
        dp[now][1 - a[now]] = -cost[now];
        return;
    }
    int l_son = krus[now].front(), r_son = krus[now].back();
    dfs(l_son);
    dfs(r_son);
    siz[now] = siz[l_son] + siz[r_son];
    for (int blk = 0; blk <= siz[now]; blk++)
    {
        dp[now][blk] = INT64_MIN;
        for (int l = max(0LL, blk - siz[r_son]); l <= min(blk, siz[l_son]); l++)
        {
            int l_black = l, l_white = siz[l_son] - l_black;
            int r_black = blk - l, r_white = siz[r_son] - r_black;
            int tmp = val[now] * (l_black * r_white + l_white * r_black);
            tmp += dp[l_son][l_black];
            tmp += dp[r_son][r_black];
            dp[now][blk] = max(dp[now][blk], tmp);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    vector<array<int, 3>> edge(n + 10);
    for (int i = 1; i < n; i++)
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    sort(edge.begin() + 1, edge.begin() + n, [](array<int, 3> a, array<int, 3> b) { return a[2] < b[2]; });
    int pos = n + 1;
    for (int i = 1; i < n; i++)
    {
        auto &[u, v, w] = edge[i];
        int fa_u = find(u), fa_v = find(v);
        if (fa_u == fa_v)
            continue;
        krus[pos].push_back(fa_u);
        krus[pos].push_back(fa_v);
        val[pos] = w;
        fa[fa_u] = pos;
        fa[fa_v] = pos;
        pos++;
    }
    int root = find(1);
    dfs(root);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, dp[root][i]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}