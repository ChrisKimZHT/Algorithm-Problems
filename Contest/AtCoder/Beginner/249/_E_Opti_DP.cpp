#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3010;
long long dp[MAXN][MAXN * 2], presum[MAXN][MAXN * 2];

inline int length(int x)
{
    if (x >= 1000)
        return 5;
    else if (x >= 100)
        return 4;
    else if (x >= 10)
        return 3;
    else
        return 2;
}

int main()
{
    int N, P;
    cin >> N >> P;
    for (int i = 1; i <= N; i++)
        dp[i][length(i)] = 26;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1, len = 2; k < i && len < j; k *= 10, len++)
            {
                int l = max(0, i - k * 10), r = i - k;
                dp[i][j] += 25 * (presum[r][j - len] - presum[l][j - len] + P) % P;
            }
            presum[i][j] = (presum[i - 1][j] + dp[i][j]) % P;
        }
    }
    long long ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans += dp[N][i];
        ans %= P;
    }
    cout << ans << endl;
    return 0;
}