#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1010;

int n1, n2, m;
vector<int> edge[SIZE];
int match[SIZE];
bool vis[SIZE];

bool find(int x)
{
    for (auto i : edge[x])
    {
        if (!vis[i])
        {
            vis[i] = true;
            if (match[i] == 0 || find(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}