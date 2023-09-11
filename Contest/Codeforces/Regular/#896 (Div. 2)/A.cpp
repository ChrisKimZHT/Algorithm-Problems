// Problem: A. Make It Zero
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n % 2 == 0)
    {
        cout << 2 << endl;
        cout << 1 << ' ' << n << endl;
        cout << 1 << ' ' << n << endl;
    }
    else
    {
        cout << 4 << endl;
        cout << 1 << ' ' << n - 1 << endl;
        cout << 1 << ' ' << n - 1 << endl;
        cout << 2 << ' ' << n << endl;
        cout << 2 << ' ' << n << endl;
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