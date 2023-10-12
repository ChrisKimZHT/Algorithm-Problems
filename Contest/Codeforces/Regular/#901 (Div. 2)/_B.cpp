// Problem: B. Jellyfish and Game
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/B
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
    int n, m, k;
    cin >> n >> m >> k;
    k = (k - 1) % 2 + 1;
    vector<int> jf(n), gf(m);
    for (int i = 0; i < n; i++)
        cin >> jf[i];
    for (int i = 0; i < m; i++)
        cin >> gf[i];
    for (int i = 1; i <= k; i++)
    {
        sort(jf.begin(), jf.end());
        sort(gf.begin(), gf.end());
        if (i % 2 == 1 && jf.front() < gf.back())
            swap(jf.front(), gf.back());
        else if (i % 2 == 0 && gf.front() < jf.back())
            swap(gf.front(), jf.back());
        // cout << accumulate(jf.begin(), jf.end(), 0LL) << endl;
    }
    cout << accumulate(jf.begin(), jf.end(), 0LL) << endl;
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