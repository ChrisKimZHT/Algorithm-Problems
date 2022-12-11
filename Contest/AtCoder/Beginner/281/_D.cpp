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
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
        dp[i][1][a[i] % D] = a[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= min(i, K); j++)
        {
            for (int k = 0; k < D; k++)
            {
                int tmp = ((k - a[i]) % D + D) % D;
                if (dp[i - 1][j - 1][tmp] != -1)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][tmp] + a[i]);
                if (dp[i - 1][j][k] != -1)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }
    cout << dp[N][K][0] << endl;
    return 0;
}