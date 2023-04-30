#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n > m) // 保证n<m
    {
        swap(n, m);
    }
    int ans = 0;
    if (n == 1)
    {
        ans = (m + 2) / 2;
    }
    else
    {
        ans = n + (m - n + 1) / 2;
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