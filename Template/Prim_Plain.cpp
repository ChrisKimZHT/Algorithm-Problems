#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
int dist[MAXN];
int vis[MAXN];
int v, e;

int prim()
{
    int ans = 0;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < v; i++)
    {
        int t = -1;
        for (int j = 1; j <= v; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (dist[t] == INF)
            return INF;
        ans += dist[t];
        vis[t] = true;
        for (int j = 1; j <= v; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return ans;
}

int main()
{
    memset(g, 0x3f, sizeof(g));
    cin >> v >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}