// Problem: E. Data Structures Fan
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/E
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
    vector<int> a(n + 10);
    int all = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all ^= a[i];
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        if (s[i - 1] == '1')
            now ^= a[i];
    vector<int> pre(n + 10);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] ^ a[i];
    int q;
    cin >> q;
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int l, r;
            cin >> l >> r;
            now ^= pre[r];
            now ^= pre[l - 1];
        }
        else
        {
            int g;
            cin >> g;
            if (g == 1)
                cout << now << ' ';
            else
                cout << (all ^ now) << ' ';
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