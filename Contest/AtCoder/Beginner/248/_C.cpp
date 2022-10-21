#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    long long dp[52][2510];
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                if (j + k <= K)
                {
                    dp[i][j + k] += dp[i - 1][j];
                    dp[i][j + k] %= MOD;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= K; i++)
    {
        ans += dp[N][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}