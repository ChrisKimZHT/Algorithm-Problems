#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int e, v, s;
vector<pair<int, int>> edge[MAXN];
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
            if (dist[cur] + next.first < dist[next.second])
            {
                dist[next.second] = dist[cur] + next.first;
                if (!vis[next.second])
                {
                    que.push(next.second);
                    vis[next.second] = true;
                }
            }
        }
    }
}

int main(void)
{
    cin >> v >> e;
    while (e--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        edge[a].push_back({dis, b});
    }
    spfa(1);
    cout << (dist[v] == INF ? "impossible" : to_string(dist[v])) << endl;
    return 0;
}