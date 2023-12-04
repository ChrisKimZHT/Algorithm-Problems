// Problem: B. Getting Points
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/B
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
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int task = (n + 6) / 7;
    auto check = [&](int x) -> bool {
        int study = n - x;
        int point = t * min(task, 2 * study) + l * study;
        return point >= p;
    };
    int a = 0, b = n;
    while (a < b)
    {
        int m = (a + b + 1) / 2;
        if (check(m))
            a = m;
        else
            b = m - 1;
    }
    cout << a << endl;
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