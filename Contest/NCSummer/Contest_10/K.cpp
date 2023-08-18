#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    long double base = 2.0L / n;
    long double ans = 1.0L;
    for (int i = 0; i < m; i++)
        ans *= base;
    cout << fixed << setprecision(18) << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}