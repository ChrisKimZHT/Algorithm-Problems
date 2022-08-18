#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, m;
char A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

int main()
{
    cin >> n >> A + 1 >> m >> B + 1;
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         dp[i][j] = INT32_MAX;
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (A[i] == B[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}