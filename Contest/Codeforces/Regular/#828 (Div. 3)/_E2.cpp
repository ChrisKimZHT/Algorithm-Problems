#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> fact_a, fact_b;
    for (ll i = 1; i * i <= a; i++)
    {
        if (!(a % i))
        {
            fact_a.push_back(i);
            if (a / i != i)
                fact_a.push_back(a / i);
        }
    }
    for (ll i = 1; i * i <= b; i++)
    {
        if (!(b % i))
        {
            fact_b.push_back(i);
            if (b / i != i)
                fact_b.push_back(b / i);
        }
    }
    for (auto i : fact_a)
    {
        for (auto j : fact_b)
        {
            ll p = i * j, q = a * b / (i * j);
            ll x = (a / p + 1) * p, y = (b / q + 1) * q;
            if (x <= c && y <= d)
            {
                cout << x << ' ' << y << endl;
                return;
            }
            x = (a / q + 1) * q, y = (b / p + 1) * p;
            if (x <= c && y <= d)
            {
                cout << x << ' ' << y << endl;
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}