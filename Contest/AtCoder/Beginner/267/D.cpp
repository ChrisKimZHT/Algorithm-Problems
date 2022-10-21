#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2022;
long long M, N, A[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    cin >> N >> M;
    for (long long i = 1; i <= N; i++)
        cin >> A[i];
    dp[0][0] = 0;
    dp[0][1] = INT64_MIN;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (j > i)
                dp[i][j] = INT64_MIN;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + A[i] * j);
        }
    cout << dp[N][M] << endl;
    return 0;
}