// Problem: D. Plus Minus Permutation
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/D
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
    int n, x, y;
    cin >> n >> x >> y;
    int lcm = x * y / __gcd(x, y);
    int same = n / lcm;
    int cnt_x = n / x - same;
    int cnt_y = n / y - same;
    int add = (n - cnt_x + 1 + n) * cnt_x / 2;
    int sub = (1 + cnt_y) * cnt_y / 2;
    cout << add - sub << endl;
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