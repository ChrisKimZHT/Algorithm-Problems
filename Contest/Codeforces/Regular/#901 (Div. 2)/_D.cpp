// Problem: D. Jellyfish and Mex
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/D
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
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ms.insert(t);
    }
    int init_mex = 0;
    while (ms.count(init_mex))
        init_mex++;
    // cout << init_mex << endl;
    vector<int> dp(n + 10, INT32_MAX);
    dp[init_mex] = 0;
    for (int i = init_mex; i >= 0; i--)
        for (int j = 0; j < i; j++)
            dp[j] = min(dp[j], dp[i] + i * (int)ms.count(j));
    cout << dp[0] - init_mex << endl;
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