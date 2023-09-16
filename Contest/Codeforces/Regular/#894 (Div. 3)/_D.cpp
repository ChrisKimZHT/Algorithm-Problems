// Problem: D. Ice Cream Balls
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int l = 2, r = 5e9;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if ((mid * (mid - 1) / 2) >= n)
            r = mid;
        else
            l = mid + 1;
    }
    if (l * (l - 1) / 2 == n)
    {
        cout << l << endl;
        return;
    }
    int delta = n - (l - 1) * (l - 2) / 2;
    cout << l - 1 + delta << endl;
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