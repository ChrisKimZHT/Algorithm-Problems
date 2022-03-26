#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#define SIZE 210
#define INF 0x3f3f3f3f

using namespace std;

struct NODE
{
    double dist;
    int point;
    NODE(int first, double second)
    {
        point = first;
        dist = second;
    }
    bool operator<(const NODE &x) const
    {
        return dist > x.dist;
    }
};

int n, cse = 0;
vector<pair<int, int>> stone;
vector<NODE> link[SIZE];
priority_queue<NODE> pque;
double dist[SIZE];
bool vis[SIZE];

void dijkstra(int x)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[x] = 0;
    pque.push(NODE(x, dist[x]));
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
            if (dist[b.point] > max(dist[a.point], b.dist))
            {
                dist[b.point] = max(dist[a.point], b.dist);
                if (!vis[b.point])
                    pque.push(NODE(b.point, dist[b.point]));
            }
        }
    }
}

int main(void)
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            stone.push_back(make_pair(x, y));
        }
        for (int i = 0; i < stone.size() - 1; i++)
        {
            for (int j = i + 1; j < stone.size(); j++)
            {
                double dis = sqrt(pow(stone[i].first - stone[j].first, 2) + pow(stone[i].second - stone[j].second, 2));
                link[i + 1].push_back(NODE(j + 1, dis));
                link[j + 1].push_back(NODE(i + 1, dis));
            }
        }
        dijkstra(1);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cse, dist[2]);
        stone.clear();
        for (int i = 0; i < SIZE; i++)
            link[i].clear();
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}