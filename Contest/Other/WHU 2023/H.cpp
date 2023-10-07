#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MOD = 998244353;

int qpow(int a, int b)
{
    int ans = 1;
    a %= MOD;
    while (b)
    {
        if (b % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = qpow(k - 1, n);
    if (n % 2)
        ans *= -1;
    ans = (ans % MOD + MOD) % MOD;
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