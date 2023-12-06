// Problem: C. Removal of Unattractive Pairs
// Contest: Codeforces - Codeforces Round 913 (Div. 3)
// URL: https://codeforces.com/contest/1907/problem/C
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
    string s;
    cin >> s;
    int cnt[26]{};
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    int mx = 0;
    for (int i = 0; i < 26; i++)
        mx = max(mx, cnt[i]);
    cout << max(n % 2, mx - (n - mx)) << endl;
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