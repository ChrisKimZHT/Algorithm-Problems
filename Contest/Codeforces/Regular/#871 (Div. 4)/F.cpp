#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n + 10);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<bool> vis(n + 10);
    queue<int> que;
    que.push(1);
    vis[1] = true;
    int far = -1;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        far = now;
        for (auto ele : edge[now])
        {
            if (vis[ele])
                continue;
            vis[ele] = true;
            que.push(ele);
        }
    }
    int node = edge[far].front();
    int a = m / edge[node].size(), b = edge[node].size() - 1;
    cout << a << ' ' << b << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}