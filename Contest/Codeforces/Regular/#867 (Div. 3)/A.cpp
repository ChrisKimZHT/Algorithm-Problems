#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = -1, pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= t - i && ans < b[i])
        {
            ans = b[i];
            pos = i + 1;
        }
    }
    cout << pos << endl;
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