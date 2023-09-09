// Problem: B. The Corridor or There and Back Again
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(210, INT32_MAX);
    for (int i = 0; i < n; i++)
    {
        int d, s;
        cin >> d >> s;
        a[d] = min(a[d], s);
    }
    int ans = INT32_MAX;
    for (int i = 1; i <= 200; i++)
    {
        if (a[i] == INT32_MAX)
            continue;
        ans = min(ans, i + (a[i] - 1) / 2);
    }
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