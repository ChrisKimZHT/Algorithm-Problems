#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 2e5 + 10, MAXM = 1e6 + 10;
int n, m, block;
int c[MAXN], ans[MAXN], cnt[MAXM];

struct Query
{
    int idx, l, r, ver;

    bool operator<(Query b)
    {
        if (l / block != b.l / block)
            return l < b.l;
        else if (r / block != b.r / block)
            return r < b.r;
        else
            return ver < b.ver;
    }
};

struct Modif
{
    int pos, color;
};

Query qu[MAXN];
Modif mo[MAXN];

int cur = 0;
void add(int x)
{
    if (cnt[x] == 0)
        cur++;
    cnt[x]++;
}

void del(int x)
{
    cnt[x]--;
    if (cnt[x] == 0)
        cur--;
}

void solve()
{
    cin >> n >> m;
    block = pow(n, 2.0 / 3);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int now_idx = 0, now_ver = 0;
    for (int i = 1; i <= m; i++)
    {
        string op;
        int x, y;
        cin >> op >> x >> y;
        if (op == "Q")
            qu[++now_idx] = {now_idx, x, y, now_ver};
        else // if (op == "R")
            mo[++now_ver] = {x, y};
    }
    sort(qu + 1, qu + 1 + now_idx);
    int l = 1, r = 0, time = 0;
    for (int i = 1; i <= now_idx; i++)
    {
        while (l > qu[i].l)
            add(c[--l]);
        while (r < qu[i].r)
            add(c[++r]);
        while (l < qu[i].l)
            del(c[l++]);
        while (r > qu[i].r)
            del(c[r--]);
        while (time < qu[i].ver)
        {
            time++;
            if (l <= mo[time].pos && mo[time].pos <= r)
            {
                add(mo[time].color);
                del(c[mo[time].pos]);
            }
            swap(mo[time].color, c[mo[time].pos]);
        }
        while (time > qu[i].ver)
        {
            if (l <= mo[time].pos && mo[time].pos <= r)
            {
                add(mo[time].color);
                del(c[mo[time].pos]);
            }
            swap(mo[time].color, c[mo[time].pos]);
            time--;
        }
        ans[qu[i].idx] = cur;
    }
    for (int i = 1; i <= now_idx; i++)
        cout << ans[i] << endl;
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