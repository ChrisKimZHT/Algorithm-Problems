#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
ll n, c, d;
vector<ll> a, ps;

inline bool check(ll x)
{
    return ps[min(x + 1, n)] * (d / (x + 1)) + ps[min(d % (x + 1), n)] >= c;
}

void solve()
{
    cin >> n >> c >> d;
    a.resize(n + 1);
    ps.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<ll>());
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];
    if (a[1] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }
    if (ps[min(n, d)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    ll l = 0, r = 2e5;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}