#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int sum = 0, cross = 0;
    for (auto &p : a)
        cin >> p.first;
    for (auto &p : a)
        cin >> p.second;
    vector<pair<int, int>> s, t;
    for (auto &[x, y] : a)
    {
        sum += abs(x - y);
        if (x < y)
            s.emplace_back(x, y);
        else if (x > y)
            t.emplace_back(y, x);
    }
    sort(s.begin(), s.end());
    vector<int> sx, sy, len;
    int rpos = INT64_MIN;
    for (auto &[x, y] : s)
    {
        if (y <= rpos)
            continue;
        rpos = y;
        sx.push_back(x);
        sy.push_back(y);
        len.push_back(y - x);
    }
    for (auto &[x, y] : t)
    {
        int tmp = 0;
        int lpos = upper_bound(sx.begin(), sx.end(), x) - sx.begin();
        int rpos = lower_bound(sy.begin(), sy.end(), y) - sy.begin();
        if (lpos > 0)
            tmp = max(tmp, min(y - x, sy[lpos - 1] - x));
        if (rpos < sy.size())
            tmp = max(tmp, min(y - x, y - sx[rpos]));
        if (rpos > lpos)
            tmp = max(tmp, *max_element(len.begin() + lpos, len.begin() + rpos));
        cross = max(cross, tmp);
    }
    cout << sum - cross * 2 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}