#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool check(int x)
{
    if (x < 0)
        return false;
    if (x >= 24)
        return false;
    return true;
}

void solve()
{
    int a[24];
    for (int i = 0; i < 24; i++)
        cin >> a[i];
    int t;
    while (cin >> t, check(t))
    {
        cout << a[t] << ' ' << (a[t] > 50 ? "Yes" : "No") << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}