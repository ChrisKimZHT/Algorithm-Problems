// Problem: B. Sequence Game
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> ans;
    ans.push_back(b[1]);
    for (int i = 2; i <= n; i++)
    {
        ans.push_back(b[i]);
        if (b[i - 1] > b[i])
            ans.push_back(b[i]);
    }
    cout << ans.size() << endl;
    for (auto &ele : ans)
        cout << ele << ' ';
    cout << endl;
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