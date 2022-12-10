#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
const int MAXN = 110;
int N, K, D;
int a[MAXN];
int dp[MAXN][MAXN][MAXN];
// [前i个][选j个][%D]

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
    {
        dp[i][1][a[i] % D] = a[i] / D;
        for (int j = i + 1; j <= N; j++)
        {
            dp[j][1][a[i] % D] = max(dp[j][1][a[i] % D], dp[i][1][a[i] % D]);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= min(i, K); j++)
        {
            for (int k = 0; k < D; k++)
            {
                int tmp = ((k - a[i]) % D + D) % D;
                if (dp[i - 1][j - 1][tmp])
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][tmp] + max(0LL, (a[i] - k) / D));
                if (dp[i - 1][j][k])
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }
    int ans = 0;
    for (int i = K; i <= N; i++)
        ans = max(ans, dp[i][K][0]);
    if (ans)
        cout << ans * D << endl;
    else
        cout << -1 << endl;
    return 0;
}