// Problem: C. Anonymous Informant
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pos = n - 1;
    for (int i = 0; i < k; i++)
    {
        if (a[pos] > n)
        {
            cout << "No" << endl;
            return;
        }
		pos = (pos - a[pos] + n) % n;
		if (pos == n - 1)
			break;
    }
    cout << "Yes" << endl;
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