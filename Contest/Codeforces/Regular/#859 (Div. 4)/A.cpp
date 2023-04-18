#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
        cout << "+" << endl;
    else
        cout << "-" << endl;
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