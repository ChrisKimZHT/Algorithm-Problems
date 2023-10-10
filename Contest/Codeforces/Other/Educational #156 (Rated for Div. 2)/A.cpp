#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 6)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 3)
    {
        cout << "YES" << endl;
        cout << 1 << ' ' << 2 << ' ' << n - 3 << endl;
    }
    else if (n == 9)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        cout << 1 << ' ' << 4 << ' ' << n - 5 << endl;
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