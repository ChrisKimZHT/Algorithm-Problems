#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

const int MAXN = 5e5 + 10, INF = 0x3f3f3f3f;
vector<int> edge[MAXN];
vector<int> d;
vector<bool> vis;
random_device rd;
mt19937 g(rd());

void dfs(int now)
{
    vis[now] = true;
    // shuffle(edge[now].begin(), edge[now].end(), g);
    for (auto &nxt : edge[now])
    {
        if (!vis[nxt])
        {
            d[nxt] = d[now] + 1;
            dfs(nxt);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    d.resize(n + 10);
    vis.resize(n + 10);
    fill(d.begin(), d.end(), 0);
    fill(vis.begin(), vis.end(), false);
    for (int i = 1; i <= n; i++)
        edge[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    // for (int j = 1; j <= n; j++)
    //     shuffle(edge[j].begin(), edge[j].end(), g);
    dfs(1);
    for (int i = 0; i < 50; i++)
    {
        auto ld = d;
        fill(d.begin(), d.end(), 0);
        fill(vis.begin(), vis.end(), false);
        for (int j = 1; j <= n; j++)
            shuffle(edge[j].begin(), edge[j].end(), g);
        dfs(1);
        if (ld != d)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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