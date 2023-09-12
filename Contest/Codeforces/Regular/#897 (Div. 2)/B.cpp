// Problem: B. XOR Palindromes
// Contest: Codeforces - Codeforces Round 897 (Div. 2)
// URL: https://codeforces.com/contest/1867/problem/B
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
    string s;
    cin >> s;
    int diff = 0;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j])
            diff++;
    for (int i = 0; i < diff; i++)
        cout << 0;
    if (n % 2)
    {
        for (int i = diff; i <= n; i++)
        {
            cout << int(i <= n - diff);
        }
    }
    else
    {
        for (int i = diff; i <= n; i++)
        {
            if ((i - diff) % 2)
                cout << 0;
            else
                cout << int(i <= n - diff);
        }
    }
    cout << endl;
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