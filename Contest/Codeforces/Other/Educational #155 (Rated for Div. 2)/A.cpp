// Problem: A. Rigged!
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/0
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
    int ss, ee;
    cin >> ss >> ee;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        if (s >= ss && e >= ee)
            flag = false;
    }
    if (flag)
        cout << ss << endl;
    else
        cout << -1 << endl;
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