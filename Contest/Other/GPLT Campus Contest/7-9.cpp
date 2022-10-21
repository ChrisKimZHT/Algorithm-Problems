#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 1e5 + 10;
int money[SIZE];
vector<int> edge[SIZE];
bool vis[SIZE];
int dist[SIZE];
int mony[SIZE];
queue<int> que;

void bfs(int src)
{
    que.push(src);
    vis[src] = true;
    dist[src] = 0;
    mony[src] = money[src];
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (auto next : edge[now])
        {
            if (!vis[next])
            {
                vis[next] = true;
                dist[next] = dist[now] + 1;
                mony[next] = mony[now] + money[next];
                que.push(next);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        edge[i].push_back(i + 1);
        if (i + 1 != n)
            edge[i + 1].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        int tp;
        cin >> tp;
        if (!(tp == -1 || tp == i))
            edge[i].push_back(tp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
    }
    bfs(m);
    cout << dist[n] << ' ' << mony[n] << endl;
    return 0;
}