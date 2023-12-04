// Problem: D. Robot Queries
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
map<char, int> dir{{'R', 0}, {'L', 1}, {'U', 2}, {'D', 3}};

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<pair<int, int>, set<int>> tra;
    vector<pair<int, int>> pos(n + 10);
    int nx = 0, ny = 0;
    tra[{0, 0}].insert(0);
    pos[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        nx += dx[dir[s[i - 1]]];
        ny += dy[dir[s[i - 1]]];
        tra[{nx, ny}].insert(i);
        pos[i] = {nx, ny};
    }
    while (q--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (tra[{x, y}].size())
        {
            if (*tra[{x, y}].begin() < l || *tra[{x, y}].rbegin() >= r)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        auto &[lx, ly] = pos[l - 1];
        auto &[rx, ry] = pos[r];
        int tx = x - lx, ty = y - ly;
        int xx = rx - tx, yy = ry - ty;
        // cout << xx << ' ' << yy << endl;
        if (tra[{xx, yy}].size())
        {
            auto pos = tra[{xx, yy}].lower_bound(l);
            if (pos != tra[{xx, yy}].end() && *pos < r)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
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