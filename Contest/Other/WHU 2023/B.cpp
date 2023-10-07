#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 5e5 + 10;
int fa[MAXN], ans[MAXN][20];
vector<int> edge[MAXN];

void dfs(int now)
{
    for (auto &nxt : edge[now])
    {
        if (fa[now] == nxt)
            continue;
        fa[nxt] = now;
        dfs(nxt);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ans[i][0];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[j][i] = ans[j][i - 1];
            for (auto &nxt : edge[j])
            {
                if (nxt == fa[j])
                    continue;
                ans[j][i] = max(ans[j][i], ans[nxt][i - 1]);
            }
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int t, x;
        cin >> t >> x;
        cout << ans[x][min(t, 19)] << endl;
    }
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