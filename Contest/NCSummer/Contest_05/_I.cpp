#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 10);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] ^ a[i];
    vector<int> f(n + 10, 1);
    for (int i = 1; i <= 3; i++)
    {
        vector<vector<int>> sum(32, vector<int>(2));
        vector<int> g(n + 10);
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= 30; k++)
            {
                int w = (pre[j] >> k) & 1;
                g[j] = (g[j] + sum[k][w ^ 1] * (1ll << k)) % MOD;
            }
            for (int k = 0; k <= 30; k++)
            {
                int w = (pre[j] >> k) & 1;
                sum[k][w] = (sum[k][w] + f[j]) % MOD;
            }
        }
        for (int j = 1; j <= n; j++)
            g[j] = (g[j] + g[j - 1]) % MOD;
        swap(f, g);
    }
    cout << f[n] << endl;
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