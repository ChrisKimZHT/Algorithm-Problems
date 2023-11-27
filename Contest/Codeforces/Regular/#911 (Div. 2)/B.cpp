// Problem: B. Laura and Operations
// Contest: Codeforces - Codeforces Round 911 (Div. 2)
// URL: https://codeforces.com/contest/1900/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

bool solve(int remain, int x, int y)
{
	return abs(x - y) % 2 == 0;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << ' ' << solve(b, c, a) << ' ' << solve(c, a, b) << endl;
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