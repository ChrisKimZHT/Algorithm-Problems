#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MOD = 998244353;

inline int func(int x, int y)
{
    return (x ^ y) * (x | y) * (x & y);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 10);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[deg[i]]++;
    int res = 0;
    for (auto &px : mp)
    {
        for (auto &py : mp)
        {
            int cntx = px.second, cnty = py.second;
            int tmp = cntx * cnty * func(px.first, py.first);
            res += tmp / 2;
            res %= MOD;
        }
    }
    cout << res % MOD << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
6 6
1 3
2 3
1 4
2 5
3 6
4 6
 */

/*
6 4
1 2
3 5
2 4
3 6
 */