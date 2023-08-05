#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int prv[MAXN];
bool tag[MAXN], vis[MAXN];

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

void bfs1(int src)
{
    memset(prv, -1, sizeof(prv));
    queue<int> que;
    que.push(src);
    prv[src] = 0;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            if (prv[nxt] != -1)
                continue;
            prv[nxt] = now;
            que.push(nxt);
        }
    }
}

int bfs2(int src)
{
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    queue<int> que;
    que.push(src);
    vis[src] = true;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        ans++;
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            if (vis[nxt] || tag[nxt])
                continue;
            vis[nxt] = true;
            que.push(nxt);
        }
    }
    return ans;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bfs1(x);
    tag[prv[y]] = true;
    for (int i = y; i != x; i = prv[i])
    {
        if (prv[i] == x)
        {
            tag[i] = true;
            break;
        }
    }
    int cnt_x = bfs2(x);
    int cnt_y = bfs2(y);
    int cnt_r = n - cnt_x - cnt_y;
    // cout << cnt_x << ' ' << cnt_y << ' ' << cnt_r << endl;
    int ans = 0;
    ans += cnt_x * (cnt_x - 1); // x-x
    ans += cnt_y * (cnt_y - 1); // y-y
    ans += cnt_r * (cnt_r - 1); // r-r
    ans += cnt_x * cnt_r * 2;   // x-r
    ans += cnt_y * cnt_r * 2;   // y-r
    ans += cnt_x * cnt_y;       // x-y
    cout << ans << endl;
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