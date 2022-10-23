/* #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 20;
int n;
ll dp[MAXN][MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
} */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 20;
int n;
ll dp[MAXN][MAXN];

ll dfs(int a, int b) // a-queue b-stack
{
    if (dp[a][b])
        return dp[a][b];
    if (!a)
        return 1;
    if (b)
        dp[a][b] += dfs(a, b - 1);
    dp[a][b] += dfs(a - 1, b + 1);
    return dp[a][b];
}

int main()
{
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}