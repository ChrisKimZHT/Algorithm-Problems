// Problem: B. 2D Traveling
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int get_dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<int, int>> cord(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> cord[i].first >> cord[i].second;
    if (a <= k && b <= k)
    {
        cout << 0 << endl;
        return;
    }
    if (a > k && b > k)
    {
        int ans = get_dist(cord[a], cord[b]);
        int t1 = 5e9, t2 = 5e9;
        for (int i = 1; i <= k; i++)
            t1 = min(t1, get_dist(cord[i], cord[a]));
        for (int i = 1; i <= k; i++)
            t2 = min(t2, get_dist(cord[i], cord[b]));
        ans = min(ans, t1 + t2);
        cout << ans << endl;
        return;
    }
    if (a > b) // make a <= b
        swap(a, b);
    int ans = 5e9;
    for (int i = 1; i <= k; i++)
    {
        int dist = get_dist(cord[i], cord[b]);
        ans = min(ans, dist);
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