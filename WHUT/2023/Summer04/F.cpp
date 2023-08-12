#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

map<char, int> mp{{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

void solve()
{
    int n;
    cin >> n;
    string op;
    cin >> op;
    int x, y;
    cin >> x >> y;
    int cnt_u = 0, cnt_d = 0, cnt_l = 0, cnt_r = 0;
    for (auto &ele : op)
    {
        if (ele == 'U')
            cnt_u++;
        else if (ele == 'D')
            cnt_d++;
        else if (ele == 'L')
            cnt_l++;
        else if (ele == 'R')
            cnt_r++;
        else
            assert(0);
    }
    int mov_x = cnt_r - cnt_l;
    int mov_y = cnt_u - cnt_d;
    // already satisfied
    if (mov_x == x && mov_y == y)
    {
        cout << 0 << endl;
        return;
    }
    // illgal cases
    if (abs(x) + abs(y) > n)
    {
        cout << -1 << endl;
        return;
    }
    if ((n - (abs(x) + abs(y))) % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    // init pre and suf
    vector<pair<int, int>> pre(n + 10), suf(n + 10);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        pre[i].first += dx[mp[op[i - 1]]];
        pre[i].second += dy[mp[op[i - 1]]];
    }
    // for (int i = 1; i <= n; i++)
    // cout << pre[i].first << ' ' << pre[i].second << endl;
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1];
        suf[i].first += dx[mp[op[i - 1]]];
        suf[i].second += dy[mp[op[i - 1]]];
    }
    // for (int i = n; i >= 1; i--)
    // cout << suf[i].first << ' ' << suf[i].second << endl;
    auto check = [&](int len) -> bool {
        // cout << len << endl;''
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int mv_x = pre[i - 1].first + suf[i + len].first;
            int mv_y = pre[i - 1].second + suf[i + len].second;
            // cout << i << ' ' << mv_x << ' ' << mv_y << endl;
            int delta_x = abs(x - mv_x), delta_y = abs(y - mv_y);
            if (delta_x + delta_y > len)
                continue;
            if ((len - (delta_x + delta_y)) % 2 != 0)
                continue;
            return true;
        }
        return false;
    };
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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