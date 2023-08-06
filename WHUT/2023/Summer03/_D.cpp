#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

typedef pair<int, int> PII;
const int MAXN = 1e3 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int E, V, S;
vector<PII> edge[MAXN], edge2[MAXN];
priority_queue<PII, vector<PII>, greater<PII>> pque;
int dist[MAXN], t[MAXN], c[MAXN];
bool vis[MAXN];

void dijkstra(int src)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[src] = 0;
    pque.push({dist[src], src});
    while (!pque.empty())
    {
        PII cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        vis[cur.second] = true;
        for (auto next : edge[cur.second])
        {
            if (dist[next.second] > dist[cur.second] + next.first)
            {
                dist[next.second] = dist[cur.second] + next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
            }
        }
    }
}

void dijkstra2(int src)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[src] = 0;
    pque.push({dist[src], src});
    while (!pque.empty())
    {
        PII cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        vis[cur.second] = true;
        for (auto next : edge2[cur.second])
        {
            if (dist[next.second] > dist[cur.second] + next.first)
            {
                dist[next.second] = dist[cur.second] + next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
    }
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> c[i];
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (dist[j] <= t[i])
                edge2[i].push_back({c[i], j});
        }
    }
    dijkstra2(x);
    if (dist[y] >= INF)
        cout << -1 << endl;
    else
        cout << dist[y] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}