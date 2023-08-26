#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> seg(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> seg[i][0] >> seg[i][1];
        seg[i][2] = i;
    }
    auto cmp = [](array<int, 3> a, array<int, 3> b) -> bool
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        if (a[1] != b[1])
            return a[1] > b[1];
        return a[2] < b[2];
    };
    sort(seg.begin() + 1, seg.begin() + 1 + n, cmp);
    int rr = -1, ri = -1;
    for (int i = 1; i <= n; i++)
    {
        auto &[l, r, id] = seg[i];
        if (r > rr)
        {
            rr = r;
            ri = id;
        }
        else
        {
            cout << id << ' ' << ri << endl;
            return;
        }
    }
    cout << -1 << ' ' << -1 << endl;
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