#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

// x > y
bool same(int x, int y)
{
    while (x > y)
        x /= 10;
    return x == y;
}

void solve()
{
    int x;
    cin >> x;
    int t = x;
    int k = 1;
    while (x < 1e18)
    {
        for (int s = sqrt(x); s * s - x < k; s++)
        {
            if (same(s * s, t))
            {
                cout << s << endl;
                return;
            }
        }
        x *= 10;
        k *= 10;
    }
    cout << -1 << endl;
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