#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

struct MergeSortTree
{
    /* ### array index must start from ONE ### */
    int n;
    vector<vector<int>> tree;

    // arr: ori arr, [s, t]: cur seg, x: cur node
    void build(const vector<int> &arr, int s, int t, int x)
    {
        if (s == t)
        {
            tree[x] = {arr[s]};
            return;
        }
        int m = s + (t - s) / 2;
        build(arr, s, m, 2 * x);
        build(arr, m + 1, t, 2 * x + 1);
        merge(tree[2 * x].begin(), tree[2 * x].end(), tree[2 * x + 1].begin(), tree[2 * x + 1].end(),
              back_inserter(tree[x]));
    }

    MergeSortTree(const vector<int> &arr) : n(arr.size())
    {
        int sz = 1 << (__lg(n) + bool(__builtin_popcount(n) - 1)); // sz = \lceil \log_{2}{n} \rceil
        tree.resize(2 * sz);
        build(arr, 1, n, 1);
    }

    // [l, r]: query array interval, [mn, mx]: query value interval, [s, t]: cur seg, x: cur node
    int count(int l, int r, int mn, int mx, int s, int t, int x)
    {
        if (l <= s && t <= r)
            return upper_bound(tree[x].begin(), tree[x].end(), mx) - lower_bound(tree[x].begin(), tree[x].end(), mn);
        int m = s + (t - s) / 2, ans = 0;
        if (l <= m)
            ans += count(l, r, mn, mx, s, m, x * 2);
        if (r > m)
            ans += count(l, r, mn, mx, m + 1, t, x * 2 + 1);
        return ans;
    }

    // query number of elements in the [l, r] interval that fall within the range [mn, mx]
    int count(int l, int r, int mn, int mx)
    {
        return count(l, r, mn, mx, 1, n, 1);
    }

    // find the kth smallest number in the [l, r] interval
    int count(int l, int r, int k)
    {
        int pl = 1, pr = n;
        while (pl < pr)
        {
            int mid = (pl + pr) / 2;
            if (count(l, r, INT32_MIN, tree[1][mid]) < k)
                pl = mid + 1;
            else
                pr = mid;
        }
        return tree[1][pl];
    }
};

int n, q;
vector<vector<int>> edge;
vector<int> in, out;
int idx = 0;

void dfs(int now, int fa)
{
    idx++;
    in[now] = idx;
    for (auto &nxt : edge[now])
        if (nxt != fa)
            dfs(nxt, now);
    out[now] = idx;
}

void solve()
{
    cin >> n >> q;
    edge.assign(n + 10, vector<int>());
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    idx = 0;
    in.resize(n + 10);
    out.resize(n + 10);
    dfs(1, 0);
    vector<int> p(n + 10), a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        a[i] = in[p[i]];
    MergeSortTree mst(a);
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (mst.count(l, r, in[x], out[x]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cout << endl;
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