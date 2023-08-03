#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int MAXN = 100010, INF = 0x3f3f3f3f;           // INF代表无穷大
int E, V;                                            // E边数 V顶点数
vector<PII> edge[MAXN];                              // 储存边，二元组为(权值,终点)
priority_queue<PII, vector<PII>, greater<PII>> pque; // 短的边在堆顶
int dist[MAXN];                                      // 储存节点到已选择点的最短距离
bool vis[MAXN];                                      // 是否已选择该点

int prim()
{
    int ans = 0, cnt = 0;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    pque.push({dist[1], 1});
    while (!pque.empty())
    {
        PII cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        ans += cur.first;
        cnt++;
        vis[cur.second] = true;
        for (auto next : edge[cur.second])
        {
            if (dist[next.second] > next.first)
            {
                dist[next.second] = next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
            }
        }
    }
    return cnt == V ? ans : INF;
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a].push_back({w, b});
        edge[b].push_back({w, a});
    }
    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}