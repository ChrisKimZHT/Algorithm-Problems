#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 3e5 + 10, MAXM = 2e6 + 10, INF = 0x3f3f3f3f;
int n, m, S, T;
int type[MAXN];

int h[MAXM], e[MAXM], w[MAXM], ne[MAXM], idx;
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dist[MAXN];
bool vis[MAXN];
priority_queue<PII, vector<PII>, greater<PII>> pque;
int dijkstra(int src, int end)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    pque.push({0, src});
    while (pque.size())
    {
        int cur = pque.top().second;
        pque.pop();
        if (vis[cur])
            continue;
        vis[cur] = true;
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            if (dist[e[i]] > dist[cur] + w[i])
            {
                dist[e[i]] = dist[cur] + w[i];
                if (!vis[e[i]])
                    pque.push({dist[e[i]], e[i]});
            }
        }
    }
    return dist[end];
}

int main()
{
    memset(h, -1, sizeof(h));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> S >> T;
    for (int i = 1; i <= n; i++)
        cin >> type[i];
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (type[a] == 1)
        {
            add(a, b + n, c);
        }
        else if (type[a] == 2)
        {
            add(a + n, b + 2 * n, c);
        }
        else
        {
            add(a, b, c);
            add(a + n, b + n, c);
            add(a + 2 * n, b + 2 * n, c);
        }
    }
    int ans = dijkstra(S, T + 2 * n);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}