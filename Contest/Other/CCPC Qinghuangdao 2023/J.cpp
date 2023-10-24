#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 13;
int cnt[MAXN];
int n, w;
int sum[1 << MAXN], dp[1 << MAXN];

void prt(int a, int b)
{
    for (int i = MAXN - 1; i >= 0; i--)
        cout << ((a >> i) & 1);
	cout << ' ';
    for (int i = MAXN - 1; i >= 0; i--)
        cout << ((b >> i) & 1);
    cout << endl;
}

void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        cnt[t - 1]++;
    }
    for (int i = 0; i < (1 << MAXN); i++)
        for (int j = 0; j < MAXN; j++)
            if (i >> j & 1)
                sum[i] += cnt[j];
    for (int i = 0; i < (1 << MAXN); i++)
        for (int j = i; j; j = (j - 1) & i)
            if (sum[j] <= w)
                dp[i] = min(dp[i], dp[i ^ j] + 1);
    cout << dp[(1 << MAXN) - 1] << endl;
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