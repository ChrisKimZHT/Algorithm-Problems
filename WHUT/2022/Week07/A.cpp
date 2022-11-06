#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    };
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll a = n - m, b = L, c = x - y;
    if (a < 0)
    {
        a = -a;
        c = -c;
    }
    ll p, q;
    ll d = exgcd(a, b, p, q);
    if (c % d)
        cout << "Impossible" << endl;
    else
        cout << (p * (c / d) % (b / d) + (b / d)) % (b / d) << endl;
    return 0;
}