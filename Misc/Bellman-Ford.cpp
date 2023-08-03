#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, MAXM = 1e4 + 10, INF = 0x3f3f3f3f;
int v, e, k;
int dist[MAXN], backup[MAXN];
struct Edge
{
    int a, b, w;
} edges[MAXM];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof(dist));
        for (int j = 0; j < e; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[v] > INF / 2 ? INF : dist[v];
}

int main()
{
    cin >> v >> e >> k;
    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    int t = bellman_ford();
    cout << (t == INF ? "impossible" : to_string(t)) << endl;
    return 0;
}