#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int n, dist[MAXN], prv[MAXN];

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int bfs1(int src)
{
    memset(dist, -1, sizeof(dist));
    memset(prv, -1, sizeof(prv));
    queue<int> que;
    int far = src;
    que.push(src);
    dist[src] = 0;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            if (dist[nxt] != -1)
                continue;
            dist[nxt] = dist[now] + 1;
            prv[nxt] = now;
            if (dist[nxt] > dist[far])
                far = nxt;
            que.push(nxt);
        }
    }
    return far;
}

int bfs2(int src)
{
    queue<int> que;
    int far = src;
    que.push(src);
    dist[src] = 0;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            if (dist[nxt] != -1)
                continue;
            dist[nxt] = dist[now] + 1;
            prv[nxt] = now;
            if (dist[nxt] > dist[far])
                far = nxt;
            que.push(nxt);
        }
    }
    return far;
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int ans = 0;
    int a = bfs1(1);
    int b = bfs1(a);
    ans += dist[b];
    memset(dist, -1, sizeof(dist));
    for (int i = b; i != -1; i = prv[i])
        dist[i] = 0;
    int c = prv[b], cans = 0;
    for (int i = b; i != -1; i = prv[i])
    {
        int tmp = bfs2(i);
        if (dist[tmp] > cans)
        {
            c = tmp;
            cans = dist[tmp];
        }
    }
    cout << ans + cans << endl;
    cout << a << ' ' << b << ' ' << c << endl;
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