// Problem: A. Don't Try to Count
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/A
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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    int cnt = 0;
	while (true)
	{
		if (x.find(s) != string::npos)
		{
			cout << cnt << endl;
			return;
		}
		cnt++;
		x += x;
		if (cnt >= 6)
			break;
	}
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