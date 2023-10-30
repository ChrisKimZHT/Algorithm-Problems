// Problem: E1. Doremy's Drying Plan (Easy Version)
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/E1
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
    vector<pair<int, int>> itv(m);
    vector<int> city(n + 10);
    vector<pair<int, pair<int, int>>> point;
    for (int i = 0; i < m; i++)
    {
        auto &[l, r] = itv[i];
        cin >> l >> r;
        city[l]++;
        city[r + 1]--;
        point.push_back({l, {i, 1}});
        point.push_back({r + 1, {i, -1}});
    }
    sort(point.begin(), point.end());
    for (int i = 1; i <= n; i++)
        city[i] += city[i - 1];
    int cnt_0 = 0;
    for (int i = 1; i <= n; i++)
        if (city[i] == 0)
            cnt_0++;
    vector<int> cov_1(n + 10);
    for (int i = 1; i <= n; i++)
        cov_1[i] = cov_1[i - 1] + (city[i] == 1);
    vector<int> cnt_1(m);
    for (int i = 0; i < m; i++)
    {
        auto &[l, r] = itv[i];
        cnt_1[i] = cov_1[r] - cov_1[l - 1];
    }
    sort(cnt_1.begin(), cnt_1.end());
    int ans = cnt_0 + cnt_1[m - 1] + cnt_1[m - 2];
    int cur = 0;
    set<int> st;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++)
    {
        while (cur < point.size() && point[cur].first == i)
        {
            if (point[cur].second.second == 1)
                st.insert(point[cur].second.first);
            else // if (point[cur].second.second == -1)
                st.erase(point[cur].second.first);
            cur++;
        }
        if (st.size() == 2)
        {
            int a = *st.begin(), b = *st.rbegin();
            mp[{a, b}]++;
        }
    }
    for (auto &[key, val] : mp)
    {
		auto &[a, b] = key;
        int ta = cov_1[itv[a].second] - cov_1[itv[a].first - 1];
        int tb = cov_1[itv[b].second] - cov_1[itv[b].first - 1];
        ans = max(ans, cnt_0 + ta + tb + val);
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