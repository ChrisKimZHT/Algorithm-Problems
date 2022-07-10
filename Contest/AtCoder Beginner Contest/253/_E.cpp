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
            ps[j] = ps[j - 1] + dp[i - 1][j];
            ps[j] %= MOD;
        }
        for (int j = 1; j <= M; j++)
        {
            if (K == 0)
            {
                dp[i][j] = ps[M];
                continue;
            }
            if (j - K >= 1)
            {
                dp[i][j] += MOD + ps[j - K] - ps[0];
                dp[i][j] %= MOD;
            }
            if (j + K <= M)
            {
                dp[i][j] += MOD + ps[M] - ps[j + K - 1];
                dp[i][j] %= MOD;
            }
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