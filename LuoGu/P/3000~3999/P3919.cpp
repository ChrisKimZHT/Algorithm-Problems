#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

namespace pst
{
    /* ### array index must start from ONE ### */

    constexpr int MAXN = 1e6;
    int n;
    int val[(MAXN << 5) + 10], lson[(MAXN << 5) + 10], rson[(MAXN << 5) + 10], cur_idx = 0;
    int root[MAXN], cur_ver = 0;

    int build(const vector<int> &arr, int s, int t)
    {
        int now = ++cur_idx;
        if (s == t)
        {
            val[now] = arr[s];
            return now;
        }
        int m = s + (t - s) / 2;
        lson[now] = build(arr, s, m);
        rson[now] = build(arr, m + 1, t);
        return now;
    }

    void init(const vector<int> &arr)
    {
        n = arr.size() - 1;
        root[0] = build(arr, 1, n);
    }

    int clone_node(int orig)
    {
        ++cur_idx;
        val[cur_idx] = val[orig];
        lson[cur_idx] = lson[orig];
        rson[cur_idx] = rson[orig];
        return cur_idx;
    }

    int update(int p, int c, int s, int t, int x)
    {
        int now = clone_node(x);
        if (s == t)
        {
            val[now] = c;
            return now;
        }
        int m = s + (t - s) / 2;
        if (p <= m)
            lson[now] = update(p, c, s, m, lson[now]);
        else
            rson[now] = update(p, c, m + 1, t, rson[now]);
        return now;
    }

    // p: upd pos, c: upd val, ver: version idx
    int update(int p, int c, int ver)
    {
        root[++cur_ver] = update(p, c, 1, n, root[ver]);
        return root[cur_ver];
    }

    int query(int p, int s, int t, int x)
    {
        if (s == t)
            return val[x];
        int m = s + (t - s) / 2;
        if (p <= m)
            return query(p, s, m, lson[x]);
        else
            return query(p, m + 1, t, rson[x]);
    }

    // p: query pos, ver: version idx
    int query(int p, int ver)
    {
        return query(p, 1, n, root[ver]);
    }

    // clone ver
    void clone(int ver)
    {
        root[++cur_ver] = root[ver];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pst::init(a);
    for (int i = 1; i <= m; i++)
    {
        int ver, op;
        cin >> ver >> op;
        if (op == 1)
        {
            int p, c;
            cin >> p >> c;
            pst::update(p, c, ver);
        }
        else
        {
            int p;
            cin >> p;
            cout << pst::query(p, ver) << endl;
            pst::clone(ver);
        }
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