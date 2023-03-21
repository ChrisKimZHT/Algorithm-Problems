#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll quick_pow(ll a, ll b, ll p) // a ^ b MOD p
{
    a %= p;
    ll ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % p;
        b /= 2;
        a = a * a % p;
    }
    return ans;
}

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

ll rev(ll a, ll m)
{
    ll x, y;
    exgcd(a, m, x, y);
    m = m < 0 ? -m : m;
    x = (x % m + m) % m;
    return x;
}

void solve()
{
    ll A, X, M;
    cin >> A >> X >> M;
    if (A == 1)
    {
        cout << X % M << endl;
        return;
    }
    ll a = rev(A - 1, M);
    ll b = (quick_pow(A, X, M) - 1 + M) % M;
    cout << a * b % M << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}