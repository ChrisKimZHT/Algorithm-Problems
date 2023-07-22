#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int x, n, m;
    cin >> x >> n >> m;
    while (x > 20 && n--)
    {
        x = x / 2 + 10;
    }
    if (x > m * 10)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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