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
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < 30; i++)
    {
        int cnt[2]{}, sum[2]{};
        cnt[0] = 1;
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            int t = (a[j] >> i) & 1;
            tmp = (tmp + (cnt[t ^ 1] * j - sum[t ^ 1] + MOD) % MOD) % MOD;
            cnt[t]++;
            sum[t] = (sum[t] + j) % MOD;
        }
        ans = (ans + tmp * (1LL << i) % MOD) % MOD;
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