#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (ll x = a + 1; x <= c; x++)
    {
        ll y = a * b / __gcd(a * b, x);
        y *= b / y + 1;
        if (y <= d)
        {
            cout << x << ' ' << y << endl;
            return;
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