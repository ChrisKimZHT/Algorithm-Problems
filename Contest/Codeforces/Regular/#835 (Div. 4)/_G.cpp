#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 10; // 无向图存双倍！
int h[MAXN], e[MAXN], ne[MAXN], we[MAXN], idx;
bool st[MAXN];
set<int> sa, sb;

inline void add(int a, int b, int w)
{
    e[idx] = b;
    we[idx] = w;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfsa(int src, int dis)
{
    memset(st, false, sizeof(st));
    queue<pair<int, int>> q;
    q.push({src, 0});
    st[src] = true;
    st[dis] = true;
    sa.insert(0);
    while (q.size())
    {
        int now = q.front().first, wt = q.front().second;
        q.pop();
        for (int i = h[now]; i != -1; i = ne[i])
        {
            int nxt = e[i];
            if (!st[nxt])
            {
                st[nxt] = true;
                int nwt = wt ^ we[i];
                sa.insert(nwt);
                q.push({nxt, nwt});
            }
        }
    }
}

void bfsb(int src)
{
    memset(st, false, sizeof(st));
    queue<pair<int, int>> q;
    q.push({src, 0});
    st[src] = true;
    while (q.size())
    {
        int now = q.front().first, wt = q.front().second;
        q.pop();
        for (int i = h[now]; i != -1; i = ne[i])
        {
            int nxt = e[i];
            if (!st[nxt])
            {
                st[nxt] = true;
                int nwt = wt ^ we[i];
                sb.insert(nwt);
                q.push({nxt, nwt});
            }
        }
    }
}

void solve()
{
    idx = 0;
    memset(h, -1, sizeof(h));
    sa.clear();
    sb.clear();
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    bfsa(a, b);
    bfsb(b);
    for (auto i : sa)
    {
        if (sb.find(i) != sb.end())
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}