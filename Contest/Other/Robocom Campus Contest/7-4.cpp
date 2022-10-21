#include <bits/stdc++.h>

using namespace std;

struct EDGE
{
    int to, dist;
    EDGE(int a, int b)
    {
        to = a;
        dist = b;
    }
};

const int SIZE = 1e5 + 20;
int n, m;
vector<EDGE> edge[SIZE];
int w[SIZE];

bool vis[SIZE];

int dfs(int point)
{
    int ans = INT32_MAX;
    bool flag = false;
    for (auto i : edge[point])
    {
        if (!vis[i.to])
        {
            vis[i.to] = true;
            int tmp = dfs(i.to) + i.dist;
            if (w[point] > tmp)
            {
                ans = min(ans, tmp);
                flag = true;
            }
            vis[i.to] = false;
        }
    }
    if (flag)
        return ans;
    else
        return w[point];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, k;
        cin >> u >> v >> k;
        edge[u].push_back({v, k});
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        vis[i] = true;
        cout << dfs(i) << ' ';
    }
    cout << endl;
    return 0;
}