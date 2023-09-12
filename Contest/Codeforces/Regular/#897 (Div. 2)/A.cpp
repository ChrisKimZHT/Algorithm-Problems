// Problem: A. green_gold_dog, array and permutation
// Contest: Codeforces - Codeforces Round 897 (Div. 2)
// URL: https://codeforces.com/contest/1867/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[a[i].second] = i;
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
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