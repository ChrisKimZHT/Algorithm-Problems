// Problem: A. Cover in Water
// Contest: Codeforces - Codeforces Round 911 (Div. 2)
// URL: https://codeforces.com/contest/1900/problem/A
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
    int cnt = 0, sum = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            cnt++;
            sum++;
        }
        else
        {
            if (cnt >= 3)
                flag = true;
            cnt = 0;
        }
    }
    if (cnt >= 3)
        flag = true;
    if (flag)
        cout << 2 << endl;
    else
        cout << sum << endl;
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