#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1010;
constexpr int MAXM = 1e6 + 10;
int h[MAXM], e[MAXM], ne[MAXM], d[MAXM], idx;
int que[MAXN];

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    d[b]++;
    h[a] = idx;
}

bool is_less(array<int, 3> &a, array<int, 3> &b)
{
    auto &[a1, a2, a3] = a;
    auto &[b1, b2, b3] = b;
    return a1 < b1 && a2 < b2 && a3 < b3;
}

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> rgb(n);
    for (int i = 0; i < n; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    if (is_less(rgb[0], rgb[1]) || is_less(rgb[1], rgb[0]))
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (is_less(rgb[i], rgb[j]))
                add(i, j);
        }
    }
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
        if (d[i] == 0)
            que[++tt] = i;
    vector<int> ans(n + 10);
    while (hh <= tt)
    {
        int now = que[hh++];
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            d[nxt]--;
            ans[nxt] = max(ans[nxt], ans[now] + 1);
            if (d[nxt] == 0)
                que[++tt] = nxt;
        }
    }
    if (ans[1] > ans[0])
    {
        ans[0] = ans[1];
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            int now = q.front();
            q.pop();
            for (int i = h[now]; i; i = ne[i])
            {
                int &nxt = e[i];
                if (ans[now] + 1 > ans[nxt])
                {
                    q.push(nxt);
                    ans[nxt] = ans[now] + 1;
                }
            }
        }
    }
    else if (ans[1] < ans[0])
    {
        ans[1] = ans[0];
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int now = q.front();
            q.pop();
            for (int i = h[now]; i; i = ne[i])
            {
                int &nxt = e[i];
                if (ans[now] + 1 > ans[nxt])
                {
                    q.push(nxt);
                    ans[nxt] = ans[now] + 1;
                }
            }
        }
    }
    if (ans[0] != ans[1])
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        assert(ans[i] >= 0);
        if (ans[i] > 255)
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << '\n';
    }
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
