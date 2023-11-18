#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    int d, last;
    cin >> d;
    // initial
    for (int i = 1; i + 1 < n; i++)
        cout << i << ' ' << i + 1 << endl;
    cout << n << ' ' << d << endl;
    cout << "-1 -1 -1" << endl;
    for (int i = 0; i < q - 1; i++)
    {
        last = d;
        cin >> d;
        if (d == last)
        {
            cout << "-1 -1 -1" << endl;
            continue;
        }
        cout << n << ' ' << last << ' ' << d << endl;
    }
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