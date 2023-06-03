#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<vector<pair<int, int>>> edge;
vector<bool> vis;
int ans;

void dfs(pair<int, int> x, int dep)
{
    ans = max(ans, dep);
    for (auto &ele : edge[x.first])
    {
        if (!vis[ele.first])
        {
            vis[ele.first] = true;
            if (ele.second > x.second)
                dfs(ele, dep);
            else
                dfs(ele, dep + 1);
            vis[ele.first] = false;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    edge.clear();
    vis.clear();
    edge.resize(n + 10);
    vis.resize(n + 10);
    ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    vis[1] = true;
    dfs({1, -1}, 1);
    cout << ans << endl;
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