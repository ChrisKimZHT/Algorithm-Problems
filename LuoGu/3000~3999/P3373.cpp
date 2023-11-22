#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 1e6 + 10;
int MOD;
int a[MAXN], d[MAXN], b[MAXN], q[MAXN];

void build(int s, int t, int p)
{
    q[p] = 1;
    if (s == t)
    {
        d[p] = a[s] % MOD;
        return;
    }
    int m = s + (t - s) / 2;
    build(s, m, 2 * p);
    build(m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1] % MOD;
}

void spread(int p, int s, int t)
{
    int m = s + (t - s) / 2;
    if (q[p] != 1 && s != t)
    {
        d[p * 2] = d[p * 2] * q[p] % MOD;
        d[p * 2 + 1] = d[p * 2 + 1] * q[p] % MOD;
        q[p * 2] = q[p * 2] * q[p] % MOD;
        q[p * 2 + 1] = q[p * 2 + 1] * q[p] % MOD;
        b[p * 2] = b[p * 2] * q[p] % MOD;
        b[p * 2 + 1] = b[p * 2 + 1] * q[p] % MOD;
        q[p] = 1;
    }
    if (b[p] && s != t)
    {
        d[p * 2] = d[p * 2] + b[p] * (m - s + 1) % MOD;
        d[p * 2 + 1] = d[p * 2 + 1] + b[p] * (t - m) % MOD;
        b[p * 2] = b[p * 2] + b[p] % MOD;
        b[p * 2 + 1] = b[p * 2 + 1] + b[p] % MOD;
        b[p] = 0;
    }
}

void add(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        d[p] = d[p] + (t - s + 1) * c % MOD;
        b[p] = b[p] + c % MOD;
        return;
    }
    spread(p, s, t);
    int m = s + (t - s) / 2;
    if (l <= m)
        add(l, r, c, s, m, p * 2);
    if (r > m)
        add(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1] % MOD;
}

void mul(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        d[p] = d[p] * c % MOD;
        b[p] = b[p] * c % MOD;
        q[p] = q[p] * c % MOD;
        return;
    }
    spread(p, s, t);
    int m = s + (t - s) / 2;
    if (l <= m)
        mul(l, r, c, s, m, p * 2);
    if (r > m)
        mul(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1] % MOD;
}

int get_sum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return d[p];
    spread(p, s, t);
    int m = s + (t - s) / 2;
    int sum = 0;
    if (l <= m)
        sum = sum + get_sum(l, r, s, m, p * 2) % MOD;
    if (r > m)
        sum = sum + get_sum(l, r, m + 1, t, p * 2 + 1) % MOD;
    return sum;
}

void solve()
{
    int n, m;
    cin >> n >> m >> MOD;
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
            mul(x, y, k, 1, n, 1);
        }
        else if (op == 2)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, y, k, 1, n, 1);
        }
        else // if (op == 3)
        {
            int x, y;
            cin >> x >> y;
            cout << get_sum(x, y, 1, n, 1) % MOD << endl;
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