#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll l, r, x;
    cin >> l >> r >> x;
    ll a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a > b)
        swap(a, b); // a <= b
    if (b - a >= x)
    {
        cout << 1 << endl;
        return;
    }
    if (a - x >= l)
    {
        cout << 2 << endl;
        return;
    }
    if (b + x <= r)
    {
        cout << 2 << endl;
        return;
    }
    if (a + x <= r && b - x >= l)
    {
        cout << 3 << endl;
        return;
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}