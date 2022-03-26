#include <iostream>
#include <vector>
#include <queue>
#define INT32_MAX 2147483647

using namespace std;

struct NODE
{
    int dist, point;
    NODE(int first, int second)
    {
        dist = first;
        point = second;
    }
    bool operator<(const NODE &x) const
    {
        return dist > x.dist;
    }
};

int T, N;
vector<NODE> link[1010];
priority_queue<NODE> pque;
int dist[1010];
bool vis[1010];

void dijkstra(int x)
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INT32_MAX;
    }
    dist[x] = 0;
    pque.push(NODE(dist[x], x));
    while (!pque.empty())
    {
        NODE a = pque.top();
        pque.pop();
        if (vis[a.point])
            continue;
        vis[a.point] = true;
        for (int i = 0; i < link[a.point].size(); i++)
        {
            NODE b = link[a.point][i];
            if (dist[a.point] + b.dist < dist[b.point])
            {
                dist[b.point] = dist[a.point] + b.dist;
                if (!vis[b.point])
                    pque.push(NODE(dist[b.point], b.point));
            }
        }
    }
}

int main(void)
{
    cin >> T >> N;
    while (T--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        link[a].push_back(NODE(dis, b));
        link[b].push_back(NODE(dis, a));
    }
    dijkstra(1);
    cout << dist[N] << endl;
    return 0;
}