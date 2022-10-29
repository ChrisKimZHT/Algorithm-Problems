#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = a.back() - a.front();
    for (int i = 1; i < n; i++)
        ans = max({ans, a.back() + a[i] - 2 * a[i - 1], 2 * a[i] - a.front() - a[i - 1]});
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}