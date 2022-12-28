#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int a, b, c, d;
// a b    c a     d c      b d
// c d    d b     b a      a c
inline bool beautiful()
{
    if (a < b && a < c && c < d && b < d)
        return true;
    if (c < a && d < b && c < d && a < b)
        return true;
    if (d < c && b < a && d < b && c < a)
        return true;
    if (b < d && a < c && b < a && d < c)
        return true;
    return false;
}

void solve()
{
    cin >> a >> b >> c >> d;
    if (beautiful())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}