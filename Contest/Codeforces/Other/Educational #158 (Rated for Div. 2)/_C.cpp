// Problem: C. Add, Divide and Floor
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1901/problem/C
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
    int mx = 0, mn = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mx = max(mx, t);
        mn = min(mn, t);
    }
    int ans = 0, add = 0;
    vector<int> op;
    while (mx != mn)
    {
        if (mx % 2 == mn % 2)
            add = 0;
        else if (mx % 2 == 0)
            add = 1;
        else
            add = 0;
        mx = (mx + add) / 2;
        mn = (mn + add) / 2;
        op.push_back(add);
        ans++;
    }
    cout << ans << endl;
    if (0 < ans && ans <= n)
    {
        for (auto &ele : op)
            cout << ele << ' ';
        cout << endl;
    }
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