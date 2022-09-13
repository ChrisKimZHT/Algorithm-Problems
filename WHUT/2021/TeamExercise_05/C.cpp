#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 1010
#define INT32_MAX 2147483647

using namespace std;

struct NODE
{
    int point, weight;
    NODE(int first, int second)
    {
        point = first;
        weight = second;
    }
    bool operator<(const NODE &x) const
    {
        return weight < x.weight;
    }
};

int T, n, m;
int weight[SIZE];
bool vis[SIZE];
vector<NODE> edge[SIZE];
priority_queue<NODE> pque;

void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
        weight[i] = 0;
    weight[src] = INT32_MAX;
    pque.push(NODE(src, weight[src]));
    while (!pque.empty())
    {
        NODE cur = pque.top();
        pque.pop();
        if (vis[cur.point])
            continue;
        vis[cur.point] = true;
        for (int i = 0; i < edge[cur.point].size(); i++)
        {
            NODE next = edge[cur.point][i];
            if (weight[next.point] < min(weight[cur.point], next.weight))
            {
                weight[next.point] = min(weight[cur.point], next.weight);
                if (!vis[next.point])
                    pque.push(NODE(next.point, weight[next.point]));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int cse = 1; cse <= T; cse++)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            edge[a].push_back(NODE(b, w));
            edge[b].push_back(NODE(a, w));
        }
        dijkstra(1);
        cout << "Scenario #" << cse << ":\n"
             << weight[n] << endl
             << endl;
        for (int i = 0; i < SIZE; i++)
            edge[i].clear();
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}