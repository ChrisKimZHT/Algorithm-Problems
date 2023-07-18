#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

typedef long long ll;
const int INF = 1e18;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// first-a second-mod
pair<ll, ll> excrt(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == -1 || b.first == -1)
        return {-1, -1};
    ll ya, yb;
    ll d = exgcd(a.second, b.second, ya, yb);
    if ((b.first - a.first) % d)
        return {-1, -1};
    ya *= (b.first - a.first) / d;
    ll tmp = b.second / d;
    ya = (ya % tmp + tmp) % tmp;
    a.first += a.second * ya;
    a.second = a.second / d * b.second;
    return a;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10), b(n + 10), c(n + 10);
    vector<int> ra(n + 10), rb(n + 10), rc(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ra[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        rb[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        rc[c[i]] = i;
    }
    vector<int> abc(n + 10), bca(n + 10), cab(n + 10);
    for (int i = 1; i <= n; i++)
    {
        abc[i] = a[b[c[i]]];
        bca[i] = b[c[a[i]]];
        cab[i] = c[a[b[i]]];
    }
    int la = 0, lb = 0, lc = 0;
    vector<int> da(n + 10, -1), db(n + 10, -1), dc(n + 10, -1);
    for (int s = 1; da[s] == -1; s = abc[s], la++)
        da[s] = la;
    for (int s = 1; db[s] == -1; s = bca[s], lb++)
        db[s] = lb;
    for (int s = 1; dc[s] == -1; s = cab[s], lc++)
        dc[s] = lc;

    auto solve = [&](int x, int y, int z) -> ll
    {
        if (da[x] == -1 || db[y] == -1 || dc[z] == -1)
            return INF;
        pair<ll, ll> p(da[x], la);
        pair<ll, ll> q(db[y], lb);
        pair<ll, ll> r(dc[z], lc);
        pair<ll, ll> ans = excrt(p, excrt(q, r));
        if (ans.first == -1)
            return INF;
        return ans.first % ans.second;
    };

    int q;
    cin >> q;
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int ans_0 = solve(x, y, z);
        int ans_1 = solve(rc[z], ra[x], rb[y]);
        int ans_2 = solve(rc[rb[y]], ra[rc[z]], rb[ra[x]]);
        int ans = min({ans_0 * 3, ans_1 * 3 + 1, ans_2 * 3 + 2});
        if (ans >= INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
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