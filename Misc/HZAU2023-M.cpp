#include <bits/stdc++.h>
// #define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;

int h[MAXN], e[MAXN], w[MAXN], ne[MAXN], idx;
void add(int a, int b, int c)
{
    idx++;
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}

int fa[MAXN], son[MAXN], dep[MAXN], siz[MAXN], val[MAXN];
void dfs1(int now)
{
    son[now] = -1;
    siz[now] = 1;
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == fa[now])
            continue;
        val[nxt] = w[i];
        dep[nxt] = dep[now] + 1;
        fa[nxt] = now;
        dfs1(nxt);
        siz[now] += siz[nxt];
        if (son[now] == -1 || siz[son[now]] < siz[nxt])
            son[now] = nxt;
    }
}

int top[MAXN], dfn[MAXN], rnk[MAXN], dfsnow;
void dfs2(int now, int tp)
{
    top[now] = tp;
    dfsnow++;
    dfn[now] = dfsnow;
    rnk[dfsnow] = now;
    if (son[now] == -1)
        return;
    dfs2(son[now], tp);
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == fa[now] || nxt == son[now])
            continue;
        dfs2(nxt, nxt);
    }
}

int sum[MAXN], mul_sum[MAXN], tag_add[MAXN], val_update[MAXN];
void push_up(int p)
{
    sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % MOD;
    mul_sum[p] = (mul_sum[p * 2] + mul_sum[p * 2 + 1]) % MOD;
}

void build(int s, int t, int p)
{
    if (s == t)
    {
        sum[p] = val[rnk[s]] % MOD;
        mul_sum[p] = val[rnk[s]] * val[rnk[s]] % MOD;
        return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    push_up(p);
}

void spread(int p, int s, int t)
{
    int m = s + (t - s) / 2;
    if (val_update[p] && s != t)
    {
        val_update[p * 2] = val_update[p];
        val_update[p * 2 + 1] = val_update[p];
        sum[p * 2] = (m - s + 1) * val_update[p] % MOD;
        sum[p * 2 + 1] = (t - m) * val_update[p] % MOD;
        mul_sum[p * 2] = ((m - s + 1) * val_update[p]) % MOD * val_update[p] % MOD;
        mul_sum[p * 2 + 1] = ((t - m) * val_update[p]) % MOD * val_update[p] % MOD;
        val_update[p] = 0;
        tag_add[p * 2] = 0;
        tag_add[p * 2 + 1] = 0;
    }
    if (tag_add[p] && s != t)
    {
        tag_add[p * 2] = (tag_add[p * 2] + tag_add[p]) % MOD;
        tag_add[p * 2 + 1] = (tag_add[p * 2 + 1] + tag_add[p]) % MOD;
        int tmp1 = sum[p * 2], tmp2 = sum[p * 2 + 1];
        sum[p * 2] = (sum[p * 2] + (m - s + 1) * tag_add[p] % MOD) % MOD;
        sum[p * 2 + 1] = (sum[p * 2 + 1] + (t - m) * tag_add[p] % MOD) % MOD;
        tmp1 = (tmp1 + sum[p * 2]) % MOD;
        tmp2 = (tmp2 + sum[p * 2 + 1]) % MOD;
        mul_sum[p * 2] = (mul_sum[p * 2] + tmp1 * tag_add[p] % MOD) % MOD;
        mul_sum[p * 2 + 1] = (mul_sum[p * 2 + 1] + tmp2 * tag_add[p] % MOD) % MOD;
        tag_add[p] = 0;
    }
}

void update(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        sum[p] = (t - s + 1) * c % MOD;
        mul_sum[p] = ((t - s + 1) * c) % MOD * c % MOD;
        val_update[p] = c % MOD;
        tag_add[p] = 0;
        return;
    }
    spread(p, s, t);
    int m = s + (t - s) / 2;
    if (l <= m)
        update(l, r, c, s, m, p * 2);
    if (r > m)
        update(l, r, c, m + 1, t, p * 2 + 1);
    push_up(p);
}

void add(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        int tmp = sum[p];
        sum[p] = (sum[p] + (t - s + 1) * c % MOD) % MOD;
        tmp = (tmp + sum[p]) % MOD;
        mul_sum[p] = (mul_sum[p] + tmp * c % MOD) % MOD;
        tag_add[p] = (tag_add[p] + c) % MOD;
        return;
    }
    spread(p, s, t);
    int m = s + (t - s) / 2;
    if (l <= m)
        add(l, r, c, s, m, p * 2);
    if (r > m)
        add(l, r, c, m + 1, t, p * 2 + 1);
    push_up(p);
}

int query(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return mul_sum[p];
    spread(p, s, t);
    int m = s + (t - s) / 2;
    int sum = 0;
    if (l <= m)
        sum = (sum + query(l, r, s, m, p * 2)) % MOD;
    if (r > m)
        sum = (sum + query(l, r, m + 1, t, p * 2 + 1)) % MOD;
    return sum;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            int ans = 0, ta = top[a], tb = top[b];
            while (top[a] != top[b])
            {
                if (dep[ta] >= dep[tb])
                {
                    ans = (ans + query(dfn[ta], dfn[a], 1, n, 1)) % MOD;
                    a = fa[ta];
                    ta = top[a];
                }
                else
                {
                    ans = (ans + query(dfn[tb], dfn[b], 1, n, 1)) % MOD;
                    b = fa[tb];
                    tb = top[b];
                }
            }
            if (dep[a] > dep[b])
                swap(a, b);
            ans = (ans + query(dfn[a] + 1, dfn[b], 1, n, 1)) % MOD;
            cout << ans << endl;
        }
        else if (op == 2)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int ta = top[a], tb = top[b];
            while (top[a] != top[b])
            {
                if (dep[ta] >= dep[tb])
                {
                    add(dfn[ta], dfn[a], c, 1, n, 1);
                    a = fa[ta];
                    ta = top[a];
                }
                else
                {
                    add(dfn[tb], dfn[b], c, 1, n, 1);
                    b = fa[tb];
                    tb = top[b];
                }
            }
            if (dep[a] > dep[b])
                swap(a, b);
            add(dfn[a] + 1, dfn[b], c, 1, n, 1);
        }
        else
        {
            int a, b, c;
            cin >> a >> b >> c;
            int ta = top[a], tb = top[b];
            while (top[a] != top[b])
            {
                if (dep[ta] >= dep[tb])
                {
                    update(dfn[ta], dfn[a], c, 1, n, 1);
                    a = fa[ta];
                    ta = top[a];
                }
                else
                {
                    update(dfn[tb], dfn[b], c, 1, n, 1);
                    b = fa[tb];
                    tb = top[b];
                }
            }
            if (dep[a] > dep[b])
                swap(a, b);
            update(dfn[a] + 1, dfn[b], c, 1, n, 1);
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