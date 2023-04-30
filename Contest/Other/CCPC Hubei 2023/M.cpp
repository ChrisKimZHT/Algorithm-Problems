#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    for (int c = 0; c <= 1e6; c++)
    {
        int p = 1000LL * x - y + 1500 * c;
        if (p < 0)
            continue;
        if (p % 1000 == 0)
        {
            int a = p / 1000;
            int kb = y - 2500 * c;
            if (kb % 1000 == 0)
            {
                int b = kb / 1000;
                if (b < 0)
                    continue;
                cout << a << ' ' << b << ' ' << c << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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