#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int h[MAXN], e[MAXN], ne[MAXN], w[MAXN], idx;
bool vis[MAXN][3];

void add(int a, int b, string s)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = s.front();
    h[a] = idx;
}

int bfs(int src, int dest)
{
    queue<array<int, 3>> que;
    que.push({src, 0, 0});
    vis[src][0] = true;
    while (que.size())
    {
        auto &[now, dist, stat] = que.front();
        que.pop();
        if (now == dest)
            return dist;
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            int &chr = w[i];
            if (stat == 0 && chr == 'W' ||
                stat == 1 && chr == 'U')
            {
                if (!vis[nxt][stat + 1])
                {
                    vis[nxt][stat + 1] = true;
                    que.push({nxt, dist + 1, stat + 1});
                }
            }
            else if (!(stat == 2 && chr == 'T'))
            {
                int stat = 0;
                if (chr == 'W')
                    stat++;
                if (!vis[nxt][stat])
                {
                    vis[nxt][stat] = true;
                    que.push({nxt, dist + 1, stat});
                }
            }
        }
    }
    return -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        string c;
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }
    cout << bfs(1, n) << endl;
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