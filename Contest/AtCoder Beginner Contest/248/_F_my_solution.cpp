#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3100;
long long dp[MAXN][MAXN][2];
int N, P;

int main()
{
    dp[0][0][0] = 1;
    dp[0][1][1] = 1;
    cin >> N >> P;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j][0] += dp[i - 1][j][1];
            dp[i][j][0] %= P;
            dp[i][j + 1][1] += dp[i - 1][j][1];
            dp[i][j + 1][1] %= P;
            dp[i][j][0] += dp[i - 1][j][0];
            dp[i][j][0] %= P;
            dp[i][j + 1][0] += 3 * dp[i - 1][j][0];
            dp[i][j + 1][0] %= P;
            dp[i][j + 2][1] += 2 * dp[i - 1][j][0];
            dp[i][j + 2][1] %= P;
        }
    }
    for (int i = 1; i < N; i++)
        cout << dp[N - 1][i][0] << ' ';
    return 0;
}