#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, MAXM = 1e4 + 10, INF = 0x3f3f3f3f;
int n, m, k;
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
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n] > INF / 2 ? INF : dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    int t = bellman_ford();
    cout << (t == INF ? "impossible" : to_string(t)) << endl;
    return 0;
}