#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

namespace hjt
{
    constexpr int MAXN = 1e6;
    int n;
    int sum[(MAXN << 5) + 10], lson[(MAXN << 5) + 10], rson[(MAXN << 5) + 10], cur_idx = 0;
    int root[MAXN], cur_ver = 0;

    int build(int s, int t)
    {
        int now = ++cur_idx;
        if (s == t)
        {
            sum[now] = 0;
            return now;
        }
        int m = s + (t - s) / 2;
        lson[now] = build(s, m);
        rson[now] = build(m + 1, t);
        return now;
    }

    int clone_node(int orig)
    {
        ++cur_idx;
        sum[cur_idx] = sum[orig] + 1;
        lson[cur_idx] = lson[orig];
        rson[cur_idx] = rson[orig];
        return cur_idx;
    }

    int update(int p, int s, int t, int x)
    {
        int now = clone_node(x);
        if (s == t)
            return now;
        int m = s + (t - s) / 2;
        if (p <= m)
            lson[now] = update(p, s, m, lson[now]);
        else
            rson[now] = update(p, m + 1, t, rson[now]);
        return now;
    }

    int query(int l, int r, int s, int t, int k)
    {
        if (s == t)
            return s;
        int x = sum[lson[r]] - sum[lson[l]];
        int m = s + (t - s) / 2;
        if (x >= k)
            return query(lson[l], lson[r], s, m, k);
        else
            return query(rson[l], rson[r], m + 1, t, k - x);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto b = a;
    sort(b.begin() + 1, b.begin() + 1 + n);
    int uni = unique(b.begin() + 1, b.begin() + 1 + n) - b.begin() - 1;
    hjt::root[0] = hjt::build(1, uni);
    for (int i = 1; i <= n; i++)
    {
        int t = lower_bound(b.begin() + 1, b.begin() + 1 + uni, a[i]) - b.begin();
        hjt::root[i] = hjt::update(t, 1, m, hjt::root[i - 1]);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int t = hjt::query(hjt::root[l - 1], hjt::root[r], 1, m, k);
        cout << b[t] << endl;
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