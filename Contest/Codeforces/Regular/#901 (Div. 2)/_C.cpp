// Problem: C. Jellyfish and Green Apple
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/C
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
    int n, m;
    cin >> n >> m;
    if (n % m == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (__builtin_popcount(m / __gcd(n, m)) != 1)
    {
        cout << -1 << endl;
        return;
    }
    int times = __gcd(n, m);
    n /= times;
    m /= times;
    int len = __lg(m);
    int ans = 0;
    for (int i = 0; i < len; i++)
        if (n >> i & 1)
            ans += ((1 << (len - i)) - 1) * (1 << i);
    ans *= times;
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