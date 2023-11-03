// Problem: A. Sorting with Twos
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/A
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
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cur = 3, nxt = 4;
    while (cur < n)
    {
        for (int i = cur; i < min(n, nxt); i++)
        {
            if (a[i] > a[i + 1])
            {
            	cout << "NO" << endl;
            	return;
            }
        }
        cur = nxt + 1;
        nxt *= 2;
    }
    cout << "YES" << endl;
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