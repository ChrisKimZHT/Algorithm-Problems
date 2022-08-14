#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, INF = 0x3f3f3f3f;
int E, V;
int dist[MAXN][MAXN];

void floyd_init(void)
{
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= V; i++)
        dist[i][i] = 0;
}

void floyd(void)
{
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void)
{
    int k;
    cin >> V >> E >> k;
    floyd_init();
    while (E--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        dist[a][b] = min(dist[a][b], dis);
    }
    floyd();
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        cout << (dist[x][y] == INF ? "impossible" : to_string(dist[x][y])) << endl;
    }
    return 0;
}