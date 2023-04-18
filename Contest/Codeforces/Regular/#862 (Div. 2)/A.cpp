#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= a[i];
    if (n % 2 == 0 && x == 0)
        cout << 0 << endl;
    else if (n % 2 == 0 && x != 0)
        cout << -1 << endl;
    else
        cout << x << endl;
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