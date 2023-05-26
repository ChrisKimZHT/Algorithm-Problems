#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int x, k;
    cin >> x >> k;
    if (x % k)
    {
        cout << 1 << endl
             << x << endl;
    }
    else
    {
        cout << 2 << endl
             << 1 << ' ' << x - 1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}