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
queue<int> que;
int dist[1010];
bool vis[1010];

void spfa(int x)
{
    for (int i = 1; i <= N; i++)
        dist[i] = INT32_MAX;
    dist[x] = 0;
    que.push(x);
    vis[x] = true;
    while (!que.empty())
    {
        int a = que.front();
        que.pop();
        vis[a] = false;
        for (int i = 0; i < link[a].size(); i++)
        {
            NODE b = link[a][i];
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
    cin >> T >> N;
    while (T--)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        link[a].push_back(NODE(dis, b));
        link[b].push_back(NODE(dis, a));
    }
    spfa(1);
    cout << dist[N] << endl;
    return 0;
}