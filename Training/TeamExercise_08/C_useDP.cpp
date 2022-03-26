#include <cstdio>

using namespace std;

int n, t;
int num[25];
int dp[25][1010];

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            dp[i + 1][j] += dp[i][j];
            if (j + num[i] <= 1000)
                dp[i + 1][j + num[i]] += dp[i][j];
        }
    }
    printf("%d\n", dp[n][t]);
}