// Problem: A. Line Trip
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1901/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 10);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = a[n] + 2 * (x - a[n]);
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
        ans = max(ans, a[i] - a[i - 1]);
    cout << ans << endl;
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