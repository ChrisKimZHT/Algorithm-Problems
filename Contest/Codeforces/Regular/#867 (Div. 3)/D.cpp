#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    cout << n << ' ';
    for (int i = n - 1; i > 1; i -= 2)
        cout << i << ' ' << n - i + 1 << ' ';
    cout << 1 << endl;
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