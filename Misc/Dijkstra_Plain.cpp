#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];
int v, e;

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < v; i++)
    {
        int t = -1;
        for (int j = 1; j <= v; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        vis[t] = true;
        for (int j = 1; j <= v; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    return dist[v] == INF ? -1 : dist[v];
}

int main()
{
    memset(g, 0x3f, sizeof(g));
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << dijkstra() << endl;
    return 0;
}