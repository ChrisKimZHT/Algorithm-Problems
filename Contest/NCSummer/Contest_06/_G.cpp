#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (x == z || y == z)
    {
        cout << "YES" << endl;
        return;
    }
    if (z == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (z % __gcd(x, y) == 0)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}