#include <bits/stdc++.h>
#define SIZE 100010

using namespace std;

int E, V;
vector<pair<int, int>> edge[SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
int dist[SIZE];
bool vis[SIZE];

void dijkstra(int src)
{
    for (int i = 1; i <= V; i++)
        dist[i] = INT32_MAX;
    dist[src] = 0;
    pque.push({dist[src], src});
    while (!pque.empty())
    {
        pair<int, int> cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        vis[cur.second] = true;
        for (auto next : edge[cur.second])
        {
            if (dist[cur.second] + next.first < dist[next.second])
            {
                dist[next.second] = dist[cur.second] + next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
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
    dijkstra(1);
    cout << (dist[V] == INT32_MAX ? -1 : dist[V]) << endl;
    return 0;
}