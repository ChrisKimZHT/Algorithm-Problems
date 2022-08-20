#include <bits/stdc++.h>

using namespace std;

const int MAXN = 310;
int N, w[MAXN];
int dp[MAXN][MAXN];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j)
                dp[i][j] = INT32_MAX;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    for (int len = 2; len <= N; len++)
        for (int l = 1, r = len; r <= N; l++, r++)
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + w[r] - w[l - 1]);
    cout << dp[1][N] << endl;
    return 0;
}