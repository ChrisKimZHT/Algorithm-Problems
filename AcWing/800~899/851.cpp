#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int dist, point;
};

const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int E, V, S;
vector<Node> edge[MAXN];
queue<int> que;
int dist[MAXN];
bool vis[MAXN];

void spfa(int src)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    que.push(src);
    vis[src] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        for (auto next : edge[cur])
        {
            if (dist[cur] + next.dist < dist[next.point])
            {
                dist[next.point] = dist[cur] + next.dist;
                if (!vis[next.point])
                {
                    que.push(next.point);
                    vis[next.point] = true;
                }
            }
        }
    }
}

int main(void)
{
    cin >> V >> E;
    while (E--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        edge[a].push_back({dis, b});
    }
    spfa(1);
    cout << (dist[V] == INF ? "impossible" : to_string(dist[V])) << endl;
    return 0;
}