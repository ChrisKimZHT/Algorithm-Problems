#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int vertice[MAXN], edge[MAXN], nxt[MAXN], idx;
int n, m;
int que[MAXN], head = 0, tail = -1;
int dist[MAXN];

int bfs(int start, int end)
{
    dist[start] = 0;
    que[++tail] = start;
    while (tail - head >= 0)
    {
        int x = que[head++];
        for (int i = vertice[x]; i != -1; i = nxt[i])
        {
            int y = edge[i];
            if (dist[y] == -1)
            {
                dist[y] = dist[x] + 1;
                que[++tail] = y;
            }
        }
    }
    return dist[end];
}

void add_edge(int a, int b)
{
    edge[idx] = b;
    nxt[idx] = vertice[a];
    vertice[a] = idx++;
}

int main()
{
    memset(vertice, -1, sizeof(vertice));
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }
    cout << bfs(1, n) << endl;
    return 0;
}