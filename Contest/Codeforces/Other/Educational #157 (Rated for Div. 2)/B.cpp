// Problem: B. Points and Minimum Distance
// Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1895/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 220;
int a[MAXN];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += abs(a[i] - a[i + 1]) + abs(a[i + n] - a[i + 1 + n]);
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ' << a[i + n] << endl;
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