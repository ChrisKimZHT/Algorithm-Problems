// Problem: A. Binary Imbalance
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/A
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
    string s;
    cin >> s;
    int cnt[2]{};
    for (int i = 0; i < n; i++)
		cnt[s[i] == '1']++;
	if (cnt[0] > cnt[1])
	{
		cout << "YES" << endl;
		return;
	}
	if (cnt[0] == 0)
	{
		cout << "NO" << endl;
		return;
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