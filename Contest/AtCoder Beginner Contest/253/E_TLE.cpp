#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, MAXM = 5010, MOD = 998244353;
int N, M, K;
long long dp[MAXN][MAXM];

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                if (abs(j - k) < K)
                    continue;
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= MOD;
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