// Problem: C. Salyg1n and the MEX Game
// Contest: Codeforces - Codeforces Round 897 (Div. 2)
// URL: https://codeforces.com/contest/1867/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
// #define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int miss = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != i)
        {
            miss = i;
            break;
        }
    }
    if (miss != -1)
        cout << miss << endl;
    else
    	cout << n << endl;
    int t;
    while (cin >> t)
    {
        if (t == -1 || t == -2)
            break;
        cout << t << endl;
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}