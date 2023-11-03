// Problem: C. Torn Lucky Ticket
// Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1895/problem/C
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
    map<pair<int, int>, int> mp;
    vector<string> ss(n);
    auto calc = [](string s) -> int {
        int sum = 0;
        for (auto &c : s)
            sum += c - '0';
        return sum;
    };
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
        mp[{ss[i].size(), calc(ss[i])}]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // pre + ss[i]
        int l = 0, r = calc(ss[i]);
        int lz = 0, rz = ss[i].size();
        ans += mp[{rz - lz, r - l}];
        for (int j = 0; j < ss[i].size(); j++)
        {
            rz--;
            lz++;
            if (rz - lz <= 0)
                break;
            r -= ss[i][j] - '0';
            l += ss[i][j] - '0';
            ans += mp[{rz - lz, r - l}];
        }
        // ss[i] + suf
        l = 0, r = calc(ss[i]);
        lz = 0, rz = ss[i].size();
        // ans += mp[{rz - lz, r - l}];
        for (int j = ss[i].size() - 1; j >= 0; j--)
        {
            rz--;
            lz++;
            if (rz - lz <= 0)
                break;
            l += ss[i][j] - '0';
            r -= ss[i][j] - '0';
            ans += mp[{rz - lz, r - l}];
        }
    }
    cout << ans << endl;
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