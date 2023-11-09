// Problem: D. Neutral Tonality
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/D
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end(), greater<int>());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            cout << b[j++] << ' ';
        else
            cout << a[i++] << ' ';
    }
    for (; i < n; i++)
        cout << a[i] << ' ';
    for (; j < m; j++)
        cout << b[j] << ' ';
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