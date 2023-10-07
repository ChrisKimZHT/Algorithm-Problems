#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

// a >= b
int cut(int a, int b)
{
    int cnt = a / b;
    int rem = a % b;
    int ans = cnt * b;
    if (rem)
        ans += cut(b, rem);
    return ans;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    if (m < n) // make m >= n
        swap(m, n);
    cout << cut(m, n) << endl;
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