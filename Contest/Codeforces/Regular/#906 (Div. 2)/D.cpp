// Problem: D. Doremy's Connecting Plan
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/D
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
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 10);
    vector<bool> st(n + 10);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 1)
            pque.push({i * c - a[i], i});
    }
    for (int i = 1; i < n; i++)
    {
        auto now = pque.top();
        if (a[1] < now.first)
        {
            cout << "No" << endl;
            return;
        }
        pque.pop();
        a[1] += a[now.second];
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