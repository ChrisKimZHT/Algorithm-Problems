#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, x, p;
    cin >> n >> x >> p;
    for (int i = 1; i <= min(p, 2 * n); i++)
    {
        int t = x + i * (i + 1) / 2;
        if (!(t % n))
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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