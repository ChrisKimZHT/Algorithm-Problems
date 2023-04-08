#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void construct_tree(vector<vector<int>> &e, vector<vector<int>> &son, vector<int> &fa)
{
    queue<int> que;
    vector<bool> vis(fa.size());
    que.push(1);
    vis[1] = true;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < e[now].size(); i++)
        {
            int nxt = e[now][i];
            if (!vis[nxt])
            {
                son[now].push_back(nxt);
                fa[nxt] = now;
                que.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

int construct_weight(int v, vector<vector<int>> &son, vector<int> &a, vector<int> &w)
{
    if (son[v].empty())
    {
        w[v] = a[v];
        return w[v];
    }
    w[v] = a[v];
    for (int i = 0; i < son[v].size(); i++)
        w[v] += construct_weight(son[v][i], son, a, w);
    return w[v];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<vector<int>> son(n + 1);
    vector<int> fa(n + 1);
    construct_tree(e, son, fa);
    vector<int> w(n + 1);
    construct_weight(1, son, a, w);
    while (m--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            cout << w[x] << endl;
        }
        else
        {
            if (son[x].empty())
                continue;
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
            // 寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄寄
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}