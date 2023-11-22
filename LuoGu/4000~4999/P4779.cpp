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
    bool operator<(const NODE &x) const
    {
        return dist > x.dist;
    }
};

int n, m, s;
vector<NODE> link[SIZE];
priority_queue<NODE> pque;
int dist[SIZE];
bool vis[SIZE];

void dijkstra(int x)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT32_MAX;
    }
    dist[x] = 0;
    pque.push(NODE(x, dist[x]));
    while (!pque.empty())
    {
        NODE a = pque.top();
        pque.pop();
        if (vis[a.point])
            continue;
        vis[a.point] = true;
        for (auto b : link[a.point])
        {
            if (dist[a.point] + b.dist < dist[b.point])
            {
                dist[b.point] = dist[a.point] + b.dist;
                if (!vis[b.point])
                    pque.push(NODE(b.point, dist[b.point]));
            }
        }
    }
}

int main(void)
{
    cin >> n >> m >> s;
    while (m--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        link[a].push_back(NODE(b, dis));
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}