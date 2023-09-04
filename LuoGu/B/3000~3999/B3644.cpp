#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 5050;
int h[MAXN], e[MAXN], d[MAXN], ne[MAXN], idx;
int que[MAXN];

void add(int a, int b)
{
    idx++;
    d[b]++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

bool topo_sort(int n) // n - vertice cnt
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            que[++tt] = i;
    while (hh <= tt)
    {
        int &now = que[hh++];
        for (int i = h[now]; i; i = ne[i])
        {
            int &nxt = e[i];
            d[nxt]--;
            if (!d[nxt])
                que[++tt] = nxt;
        }
    }
    return tt == n - 1;
}

void solve()
{
    int n;
    cin >> n;
    int t;
    for (int i = 1; i <= n; i++)
        while (cin >> t, t)
            add(i, t);
    topo_sort(n);
    for (int i = 0; i < n; i++)
        cout << que[i] << ' ';
    cout << endl;
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