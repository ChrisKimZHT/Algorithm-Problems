#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 2e5 + 10;
int prime[MAXN], idx;
bool not_prime[MAXN];
int n;
int a[MAXN];
int dp[MAXN][4];

void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    dp[1][1] = dp[1][2] = dp[1][3] = 1;
    for (int i = 2; i <= n; i++)
    {
        // 0 -> 0
        if (!not_prime[a[i - 1] + a[i]])
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        // 1 -> 0
        if (!not_prime[1 + a[i]])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        // 2 -> 0
        if (a[i] % 2)
            dp[i][0] = min(dp[i][0], dp[i - 1][2]);
        // 3 -> 0
        else
            dp[i][0] = min(dp[i][0], dp[i - 1][3]);
        ///////////////////////////////////////////////
        // 0 -> 1
        if (!not_prime[a[i - 1] + 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        // 1 -> 1
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
        // 2 -> 1
        dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
        // 3 -> 1: illegal
        ///////////////////////////////////////////////
        // 0 -> 2
        if (a[i - 1] % 2)
            dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        // 1 -> 2
        dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
        // 2 -> 2: illegal
        // 3 -> 2
        dp[i][2] = min(dp[i][2], dp[i - 1][3] + 1);
        ///////////////////////////////////////////////
        // 0 -> 3
        if (a[i - 1] % 2 == 0)
            dp[i][3] = min(dp[i][3], dp[i - 1][0] + 1);
        // 1 -> 3: illegal
        // 2 -> 3
        dp[i][3] = min(dp[i][3], dp[i - 1][2] + 1);
        // 3 -> 3: illegal
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_prime();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}