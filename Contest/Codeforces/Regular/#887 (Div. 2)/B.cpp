#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int la = 1, lb = 0;
    int a = 0, b = 1;
    for (int i = 3; i <= k; i++)
    {
        int ta = la, tb = lb;
        la = a;
        lb = b;
        a += ta;
        b += tb;
        if (min(a, b) > n)
        {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 0;
    for (int x = 0; a * x <= n; x++)
    {
        int y = (n - a * x) / b;
        if (x > y)
            break;
        if (a * x + b * y == n)
        {
            // cout << a << ' ' << b << endl;
            // cout << x << ' ' << y << endl
            //      << endl;
            ans++;
        }
    }
    cout << ans << endl;
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