// Problem: C. Fill in the Matrix
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
            cout << 0 << endl;
        return;
    }
    if (n + 1 >= m)
    {
        cout << m << endl;
        for (int i = 0; i < m - 1; i++)
            for (int j = 0; j < m; j++)
                cout << (j + i) % m << " \n"[j + 1 == m];
        for (int i = m - 1; i < n; i++)
            for (int j = 0; j < m; j++)
                cout << j << " \n"[j + 1 == m];
    }
    else
    {
        cout << n + 1 << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cout << (j + i) % m << " \n"[j + 1 == m];
    }
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