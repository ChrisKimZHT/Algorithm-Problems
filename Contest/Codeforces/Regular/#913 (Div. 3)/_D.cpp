// Problem: D. Jumping Through Segments
// Contest: Codeforces - Codeforces Round 913 (Div. 3)
// URL: https://codeforces.com/contest/1907/problem/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++)
        cin >> seg[i].first >> seg[i].second;
    auto check = [&](int x) -> bool {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            a -= x;
            b += x;
            a = max(a, seg[i].first);
            b = min(b, seg[i].second);
            if (a > b)
                return false;
        }
        return true;
    };
    int l = 0, r = 1e9;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
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