#include <bits/stdc++.h>
#define int long long
// #define endl '\n'

using namespace std;

int query(int r, int c)
{
    cout << "? " << r << " " << c << endl;
    int t;
    cin >> t;
    return t;
}

void ans(int r, int c)
{
    cout << "! " << r << " " << c << endl;
    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a = query(1, 1);
    a++;
    if (a > m)
    {
        int b = query(a, 1);
        b++;
        ans(a, b);
        return;
    }
    if (a > n)
    {
        int b = query(1, a);
        b++;
        ans(b, a);
        return;
    }
    int b = query(a, 1);
    b++;
    if (b < a)
    {
        ans(a, b);
        return;
    }
    int c = query(1, a);
    c++;
    if (c < a)
    {
        ans(c, a);
        return;
    }
    ans(a, a);
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