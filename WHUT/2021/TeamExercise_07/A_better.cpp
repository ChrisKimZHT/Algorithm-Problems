#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 10;

int V, E;
vector<int> edge[SIZE];
int color[SIZE];
vector<int> ans[2];

bool dfs(int node, int colr)
{
    color[node] = colr;
    ans[colr].push_back(node);
    for (auto next : edge[node])
    {
        if (color[next] == -1)
        {
            if (!dfs(next, !colr))
                return false;
        }
        else if (color[next] == colr)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    memset(color, -1, sizeof(color));
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bool flag = true;
    for (int i = 1; i <= V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0))
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << ans[0].size() << endl;
        for (int i = 0; i < ans[0].size(); i++)
            cout << ans[0][i] << ' ';
        cout << endl;
        cout << ans[1].size() << endl;
        for (int i = 0; i < ans[1].size(); i++)
            cout << ans[1][i] << ' ';
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}