// Problem: E. Freedom of Choice
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/E
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
    int m;
    cin >> m;
    vector<int> n(m), l(m), r(m), s(m);
    vector<vector<int>> a(m), c(m);
    int sl = 0, sr = 0, sn = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> n[i] >> l[i] >> r[i];
        sn += n[i];
        sl += l[i];
        sr += r[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++)
            cin >> a[i][j];
        for (int j = 0; j < n[i]; j++)
            cin >> c[i][j];
        s[i] = accumulate(c[i].begin(), c[i].end(), 0LL);
    }
    if (sr - sl + 1 > sn)
    {
        cout << 0 << endl;
        return;
    }
    map<int, int> sum;
    map<int, vector<pair<int, int>>> idx;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n[i]; j++)
        {
            sum[a[i][j]] += r[i];
            idx[a[i][j]].push_back({i, j});
        }
    }

    int ans = INT64_MAX;
    for (int i = sl; i <= sr; i++)
    {
        int need = 0, size = sr - sum[i];
        for (auto &[p, q] : idx[i])
        {
            int t = s[p] - c[p][q];
            if (t < l[p])
            {
                need += l[p] - t;
                size += l[p];
            }
            else
            {
                size += min(t, r[p]);
            }
        }
        ans = min(ans, need + max(i - size, 0LL));
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