#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, INF = 0x3f3f3f3f;
int graph[MAXN][MAXN];
int dist[MAXN];
bool st[MAXN];
int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + graph[t][j]);
    }
    return dist[n] == INF ? -1 : dist[n];
}

int main()
{
    memset(graph, 0x3f, sizeof(graph));
    cin >> n >> m;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = min(graph[x][y], z);
    }
    cout << dijkstra() << endl;
    return 0;
}