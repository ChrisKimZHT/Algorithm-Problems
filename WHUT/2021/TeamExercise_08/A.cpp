#include <cstdio>
#include <algorithm>

using namespace std;

const int SIZE = 11;

int n;
int mp[SIZE][SIZE];
int dp[SIZE][SIZE][SIZE][SIZE];

inline int max4(int a, int b, int c, int d)
{
    return max(max(max(a, b), c), d);
}

int main()
{
    scanf("%d", &n);
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
        mp[a][b] = c;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                for (int y2 = 1; y2 <= n; y2++)
                {
                    dp[x1][y1][x2][y2] = max4(dp[x1 - 1][y1][x2 - 1][y2],
                                              dp[x1 - 1][y1][x2][y2 - 1],
                                              dp[x1][y1 - 1][x2 - 1][y2],
                                              dp[x1][y1 - 1][x2][y2 - 1]) +
                                         mp[x1][y1] + mp[x2][y2];
                    if (x1 == x2 && y1 == y2)
                        dp[x1][y1][x2][y2] -= mp[x1][y1];
                }
            }
        }
    }
    printf("%d\n", dp[n][n][n][n]);
    return 0;
}