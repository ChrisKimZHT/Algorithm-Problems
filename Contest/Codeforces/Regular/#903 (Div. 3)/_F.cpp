// Problem: F. Minimum Maximum Distance
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 4e5 + 10;
int e[MAXN], ne[MAXN], h[MAXN], idx;
bool tag[MAXN];

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int far = -1, dis = -1;
void dfs(int now, int fa, int dep)
{
    if (tag[now] && dep > dis)
    {
        dis = dep;
        far = now;
    }
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == fa)
            continue;
        dfs(nxt, now, dep + 1);
    }
}

void solve()
{
    idx = 0;
    memset(h, 0, sizeof(h));
    memset(tag, false, sizeof(tag));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        tag[t] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    if (k == 1)
    {
        cout << 0 << endl;
        return;
    }
    dis = -1;
    dfs(1, 0, 0);
    dis = -1;
    dfs(far, 0, 0);
    cout << (dis + 1) / 2 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}