// Problem: B. Deja Vu
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/B
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> op;
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (op.empty() || op.back() > t)
        {
            op.push_back(t);
            continue;
        }
    }
    for (int i = 1; i <= n; i++)
        for (auto &t : op)
            if (((a[i] >> t) << t) == a[i])
                a[i] += (1 << (t - 1));
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
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