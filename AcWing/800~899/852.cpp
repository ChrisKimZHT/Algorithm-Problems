#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int E, V, S;
vector<pair<int, int>> edge[MAXN];
queue<int> que;
int dist[MAXN], cnt[MAXN];
bool vis[MAXN];

bool spfa()
{
    for (int i = 1; i <= V; i++)
    {
        que.push(i);
        vis[i] = true;
    }
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
                cnt[next.second] = cnt[cur] + 1;
                if (cnt[next.second] >= V)
                    return true;
                if (!vis[next.second])
                {
                    que.push(next.second);
                    vis[next.second] = true;
                }
            }
        }
    }
    return false;
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
    cout << (spfa() ? "Yes" : "No") << endl;
    return 0;
}