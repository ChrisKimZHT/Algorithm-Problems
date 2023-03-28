#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string a;
    int b, c;
    cin >> a >> b >> c;
    if (!(15 <= b && b <= 20 && 50 <= c && c <= 70))
        cout << a << endl;
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