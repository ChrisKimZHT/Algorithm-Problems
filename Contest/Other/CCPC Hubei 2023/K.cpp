#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int mod = 998244353;
int qpow(int x, int y)
{
    int ans = 1LL;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = m; i >= 1; i--)
        cout << (qpow(i - 1, n) * qpow(qpow(m - 1, n), mod - 2) % mod) << ' ';
    cout << endl;
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