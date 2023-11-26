// Problem: D. Yet Another Monster Fight
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1901/problem/D
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
    int n;
    cin >> n;
    vector<int> a(n + 10);
    multiset<int> l{0}, r{0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r.insert(a[i] + i - 1);
    }
    int ans = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        r.extract(a[i] + i - 1);
        ans = min(ans, max({a[i], *l.rbegin(), *r.rbegin()}));
        l.insert(a[i] + n - i);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}