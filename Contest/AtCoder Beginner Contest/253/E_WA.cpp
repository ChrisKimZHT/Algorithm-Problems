#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, MAXM = 5010, MOD = 998244353;
int N, M, K;
long long dp[MAXN][MAXM];
long long ps[MAXM];

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
    {
        memset(ps, 0, sizeof(ps));
        for (int j = 1; j <= M; j++)
        {
            if (j - K >= 1)
            {
                ps[0] += dp[i - 1][j];
                ps[0] %= MOD;
                ps[j - K] += MOD - dp[i - 1][j];
                ps[j - K] %= MOD;
            }
            if (j + K <= M)
            {
                ps[j + K - 1] += dp[i - 1][j];
                ps[j + K - 1] %= MOD;
                ps[M] += MOD - dp[i - 1][j];
                ps[M] %= MOD;
            }
        }
        for (int j = 0; j <= M; j++)
        {
            dp[i][j + 1] = dp[i][j] + ps[j];
            dp[i][j + 1] %= MOD;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= M; i++)
    {
        ans += dp[N][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}