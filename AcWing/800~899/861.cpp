#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, MAXM = 1e5 + 10;
int n1, n2, m;
int h[MAXM], e[MAXM], ne[MAXM], idx;
int match[MAXN];
bool vis[MAXN];

inline void add_edge(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int y = e[i];
        if (!vis[y])
        {
            vis[y] = true;
            if (match[y] == 0 || find(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n1 >> n2 >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (find(i))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}