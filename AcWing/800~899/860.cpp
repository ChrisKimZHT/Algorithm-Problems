#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int n, m;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int color[MAXN];

inline void add_edge(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int n, int c)
{
    color[n] = c;
    for (int i = h[n]; i != -1; i = ne[i])
    {
        int d = e[i];
        if (color[d] == -1)
        {
            if (!dfs(d, !c))
                return false;
        }
        else if (color[d] == c)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    memset(color, -1, sizeof(color));
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
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
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}