// Problem: D. XOR Construction
// Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1895/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n - 1; i++)
        cin >> a[i];
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i <= n - 1; i++)
        ans.push_back(ans.back() ^ a[i]);
    vector<int> cnt(32), base(32);
    for (int i = 1; i <= n - 1; i++)
        for (int j = 0; j < 32; j++)
            if (i >> j & 1)
                base[j]++;
    for (auto &ele : ans)
        for (int j = 0; j < 32; j++)
            if (ele >> j & 1)
                cnt[j]++;
    // for (auto &ele : cnt)
        // cout << ele << ' ';
    // cout << endl;
    // for (auto &ele : base)
        // cout << ele << ' ';
    // cout << endl;
    int offset = 0;
    for (int i = 0; i < 32; i++)
        if (base[i] != cnt[i])
            offset ^= (1 << i);
    for (auto &ele : ans)
        cout << (ele ^ offset) << ' ';
    cout << endl;
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