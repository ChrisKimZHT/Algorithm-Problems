#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 0)
    {
        a += c / 2;
        b += c / 2;
    }
    else
    {
        a += c / 2 + 1;
        b += c / 2;
    }
    if (a > b)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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