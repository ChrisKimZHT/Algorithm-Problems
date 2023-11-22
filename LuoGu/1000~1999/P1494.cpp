#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 5e4 + 10;
int n, m, block;
int c[MAXN], cnt[MAXN];
pair<int, int> ans[MAXN];

struct Query
{
    int id, l, r;

    bool operator<(Query b)
    {
        if (l / block != b.l / block)
            return l < b.l;
        return (l / block) % 2 ? r < b.r : r > b.r;
    }
};

Query qu[MAXN];

int cur = 0;
void add(int x)
{
    cur += cnt[x];
    cnt[x]++;
}

void del(int x)
{
    cnt[x]--;
    cur -= cnt[x];
}

void solve()
{
    cin >> n >> m;
    block = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }
    sort(qu + 1, qu + 1 + m);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        if (qu[i].l == qu[i].r)
        {
            ans[qu[i].id] = {0, 1};
            continue;
        }
        while (l > qu[i].l)
            add(c[--l]);
        while (r < qu[i].r)
            add(c[++r]);
        while (l < qu[i].l)
            del(c[l++]);
        while (r > qu[i].r)
            del(c[r--]);
        ans[qu[i].id] = {cur, (r - l + 1) * (r - l) / 2};
    }
    for (int i = 1; i <= m; i++)
    {
        auto &[a, b] = ans[i];
        if (a == 0)
        {
            cout << "0/1" << endl;
            continue;
        }
        int g = gcd(a, b);
        cout << a / g << '/' << b / g << endl;
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