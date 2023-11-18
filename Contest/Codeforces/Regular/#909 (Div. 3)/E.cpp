#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int pos = 0, mn = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < mn)
        {
            mn = a[i];
            pos = i;
        }
    }
    for (int i = pos + 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << pos << endl;
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