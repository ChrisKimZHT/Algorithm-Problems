#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 2e5 + 10, MAXM = 30, MOD = 998244353;
int n, a[MAXN], f[MAXN], s[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
        s[i] = 1;
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j <= MAXM; j++)
        {
            int c[2] = {i == 1, 0};
            for (int k = 1; k <= n; k++)
            {
                int t = a[k] >> j & 1;
                f[k] = (f[k] + (c[t ^ 1] << j)) % MOD;
                c[t] = (c[t] + s[k]) % MOD;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            s[j] = (s[j - 1] + f[j]) % MOD;
            f[j] = 0;
        }
    }
    cout << s[n] << endl;
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