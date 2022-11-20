#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10, MOD = 1e9 + 7;
int fa[MAXN], ds[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int n)
{
    if (fa[n] == n)
        return n;
    int res = find(fa[n]);
    ds[n] += ds[fa[n]];
    return fa[n] = res;
}

void merge(int a, int b)
{
    int faa = find(a), fab = find(b);
    fa[faa] = fab;
    ds[faa] = ds[b] - ds[a] + 1;
}

signed main()
{
    int n;
    cin >> n;
    init(n);
    vector<pair<int, int>> w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i].first;
        w[i].second = i;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
        find(i);
    sort(w.begin() + 1, w.end());
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + abs(ds[w[i].second] - ds[1]);
    }
    int ans = 0;
    for (int i = n; i > 1; i--)
    {
        ans += w[i].first * ((i - 1) * abs(ds[w[i].second] - ds[1]) + pre[i - 1]);
        ans %= MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}