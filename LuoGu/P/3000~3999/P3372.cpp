#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN], d[MAXN], b[MAXN];

void build(int s, int t, int p)
{
    if (s == t)
    {
        d[p] = a[s];
        return;
    }
    int m = s + (t - s) / 2;
    build(s, m, 2 * p);
    build(m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1];
}

void add(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }
    int m = s + (t - s) / 2;
    if (b[p] && s != t)
    {
        d[p * 2] += b[p] * (m - s + 1);
        d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p];
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }
    if (l <= m)
        add(l, r, c, s, m, p * 2);
    if (r > m)
        add(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

int get_sum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return d[p];
    int m = s + (t - s) / 2;
    if (b[p])
    {
        d[p * 2] += b[p] * (m - s + 1);
        d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p];
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }
    int sum = 0;
    if (l <= m)
        sum += get_sum(l, r, s, m, p * 2);
    if (r > m)
        sum += get_sum(l, r, m + 1, t, p * 2 + 1);
    return sum;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, y, k, 1, n, 1);
        }
        else // if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << get_sum(x, y, 1, n, 1) << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}