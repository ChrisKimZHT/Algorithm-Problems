#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10, MOD = 1e4;
/*
 *   0   1   2   3
 *  *   **  *   **
 *  *   *   **  **
 */
int dp[MAXN][4];
int N;

int main()
{
    cin >> N;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] += dp[i - 1][0] + dp[i - 1][3];
        dp[i][1] += dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] += dp[i - 1][0] + dp[i - 1][1];
        dp[i][3] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i][3] %= MOD;
    }
    cout << dp[N][0] << endl;
    return 0;
}