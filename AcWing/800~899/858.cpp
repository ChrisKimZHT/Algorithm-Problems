#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
int dist[MAXN];
int vis[MAXN];
int n, m;

int prim()
{
    int ans = 0;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (dist[t] == INF)
            return INF;
        ans += dist[t];
        vis[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return ans;
}

int main()
{
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}