#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e5 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int fa[MAXN], dep[MAXN], son[MAXN], siz[MAXN];
int top[MAXN], dfn[MAXN], rnk[MAXN], cnt;
int w[MAXN];

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

void dfs1(int now)
{
    son[now] = -1;
    siz[now] = 1;
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == fa[now])
            continue;
        fa[nxt] = now;
        dep[nxt] = dep[now] + 1;
        dfs1(nxt);
        siz[now] += siz[nxt];
        if (son[now] == -1 || siz[son[now]] < siz[nxt])
            son[now] = nxt;
    }
}

void dfs2(int now, int pre)
{
    top[now] = pre;
    dfn[now] = ++cnt;
    rnk[cnt] = now;
    if (son[now] == -1)
        return;
    dfs2(son[now], pre);
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == son[now] || nxt == fa[now])
            continue;
        dfs2(nxt, nxt);
    }
}

int d[MAXN], mx[MAXN], b[MAXN], v[MAXN];
void build(int s, int t, int p)
{
    if (s == t)
    {
        d[p] = mx[p] = w[rnk[s]];
        return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
    mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}

void update(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        d[p] = (t - s + 1) * c;
        b[p] = 1;
        v[p] = c;
        mx[p] = c;
        return;
    }
    int m = s + (t - s) / 2;
    if (b[p] && s != t)
    {
        mx[p * 2] = v[p];
        mx[p * 2 + 1] = v[p];
        d[p * 2] = v[p] * (m - s + 1);
        d[p * 2 + 1] = v[p] * (t - m);
        v[p * 2] = v[p];
        v[p * 2 + 1] = v[p];
        b[p * 2] = 1;
        b[p * 2 + 1] = 1;
        b[p] = 0;
    }
    if (l <= m)
        update(l, r, c, s, m, p * 2);
    if (r > m)
        update(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
    mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}

int get_sum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return d[p];
    int m = s + (t - s) / 2;
    if (b[p])
    {
        mx[p * 2] = v[p];
        mx[p * 2 + 1] = v[p];
        d[p * 2] = v[p] * (m - s + 1);
        d[p * 2 + 1] = v[p] * (t - m);
        v[p * 2] = v[p];
        v[p * 2 + 1] = v[p];
        b[p * 2] = 1;
        b[p * 2 + 1] = 1;
        b[p] = 0;
    }
    int sum = 0;
    if (l <= m)
        sum += get_sum(l, r, s, m, p * 2);
    if (r > m)
        sum += get_sum(l, r, m + 1, t, p * 2 + 1);
    return sum;
}

int get_max(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return mx[p];
    int m = s + (t - s) / 2;
    if (b[p])
    {
        mx[p * 2] = v[p];
        mx[p * 2 + 1] = v[p];
        d[p * 2] = v[p] * (m - s + 1);
        d[p * 2 + 1] = v[p] * (t - m);
        v[p * 2] = v[p];
        v[p * 2 + 1] = v[p];
        b[p * 2] = 1;
        b[p * 2 + 1] = 1;
        b[p] = 0;
    }
    int ans = INT32_MIN;
    if (l <= m)
        ans = max(ans, get_max(l, r, s, m, p * 2));
    if (r > m)
        ans = max(ans, get_max(l, r, m + 1, t, p * 2 + 1));
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);
    build(1, n, 1);
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "CHANGE")
        {
            update(dfn[a], dfn[a], b, 1, n, 1);
        }
        else if (op == "QMAX")
        {
            int ans = INT32_MIN, ta = top[a], tb = top[b];
            while (top[a] != top[b])
            {
                if (dep[ta] >= dep[tb])
                {
                    ans = max(ans, get_max(dfn[ta], dfn[a], 1, n, 1));
                    a = fa[ta];
                    ta = top[a];
                }
                else
                {
                    ans = max(ans, get_max(dfn[tb], dfn[b], 1, n, 1));
                    b = fa[tb];
                    tb = top[b];
                }
            }
            if (dfn[a] < dfn[b])
                ans = max(ans, get_max(dfn[a], dfn[b], 1, n, 1));
            else
                ans = max(ans, get_max(dfn[b], dfn[a], 1, n, 1));
            cout << ans << endl;
        }
        else if (op == "QSUM")
        {
            int ans = 0, ta = top[a], tb = top[b];
            while (top[a] != top[b])
            {
                if (dep[ta] >= dep[tb])
                {
                    ans += get_sum(dfn[ta], dfn[a], 1, n, 1);
                    a = fa[ta];
                    ta = top[a];
                }
                else
                {
                    ans += get_sum(dfn[tb], dfn[b], 1, n, 1);
                    b = fa[tb];
                    tb = top[b];
                }
            }
            if (dfn[a] < dfn[b])
                ans += get_sum(dfn[a], dfn[b], 1, n, 1);
            else
                ans += get_sum(dfn[b], dfn[a], 1, n, 1);
            cout << ans << endl;
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