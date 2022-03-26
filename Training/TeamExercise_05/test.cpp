#include <bits/stdc++.h>
#define SIZE 100010

using namespace std;

struct NODE
{
    int dist, point;
    NODE(int first, int second)
    {
        point = first;
        dist = second;
    }
};

int E, V, S;
int dist[SIZE];
bool vis[SIZE];
vector<NODE> link[SIZE];
queue<int> que;

void spfa(int x)
{
    for (int i = 1; i <= V; i++)
        dist[i] = INT32_MAX;
    dist[x] = 0;
    que.push(x);
    vis[x] = true;
    while (!que.empty())
    {
        int a = que.front();
        que.pop();
        vis[a] = false;
        for (auto b : link[a])
        {
            if (dist[a] + b.dist < dist[b.point])
            {
                dist[b.point] = dist[a] + b.dist;
                if (!vis[b.point])
                {
                    que.push(b.point);
                    vis[b.point] = true;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> E >> V >> S;
    while (E--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        link[a].push_back(NODE(b, dis));
        // 若双向都能通过，添加 link[b].push_back(NODE(a, dis));
    }
    spfa(S);
    for (int i = 1; i <= V; i++)
        cout << dist[i] << ' ';
    return 0;
}