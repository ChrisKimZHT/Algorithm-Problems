// Problem: B. Qingshan Loves Strings
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/B
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "Yes" << endl;
        return;
    }
    for (int i = 1; i < m; i++)
    {
        if (t[i - 1] == t[i])
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            if (s[i - 1] == t.front() || s[i] == t.back())
            {
                cout << "No" << endl;
                return;
            }
        }
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