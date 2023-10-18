// Problem: B. Three Threadlets
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/B
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
    int len[3];
    cin >> len[0] >> len[1] >> len[2];
    int g = gcd(len[0], gcd(len[1], len[2]));
    len[0] /= g;
    len[1] /= g;
    len[2] /= g;
    sort(len, len + 3);
    if (len[0] + len[1] + len[2] <= 6)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;
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