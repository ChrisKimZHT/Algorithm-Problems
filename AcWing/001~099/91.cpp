#include <bits/stdc++.h>

using namespace std;

const int MAXN = 21;
int n;
int a[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if ((i - (1 << j)) >> k & 1)
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[k][j]);
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}