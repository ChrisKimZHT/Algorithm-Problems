// Problem: B. Chips on the Board
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/B
// Memory Limit: 256 MB
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
    vector<int> a(n + 10), b(n + 10);
    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sum_b += b[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + n);
    int ans_1 = a[1] * n + sum_b;
    int ans_2 = b[1] * n + sum_a;
    cout << min(ans_1, ans_2) << endl;
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