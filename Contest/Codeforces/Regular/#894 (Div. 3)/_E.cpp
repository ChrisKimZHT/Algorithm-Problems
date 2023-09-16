// Problem: E. Kolya and Movie Theatre
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/E
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
    int n, m, d;
    cin >> n >> m >> d;
    int ans = 0, sum = 0;
    multiset<int> ms;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t < 0)
            continue;
        ms.insert(t);
        sum += t;
        if (ms.size() > m)
        {
            int mn = *ms.begin();
            ms.extract(mn);
            sum -= mn;
        }
        ans = max(ans, sum - i * d);
    }
    cout << ans << endl;
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