/* #include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, MOD = 1e9 + 7;
long long dp[MAXN][MAXN];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; j >= k * i; k++)
                dp[i][j] += dp[i - 1][j - k * i] % MOD;
    cout << dp[n][n] << endl;
    return 0;
} */

/* #include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, MOD = 1e9 + 7;
long long dp[MAXN];
int n;

int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n; j > 0; j--)
            for (int k = 1; j >= k * i; k++)
                dp[j] += dp[j - k * i] % MOD;
    cout << dp[n] % MOD << endl;
    return 0;
} */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, MOD = 1e9 + 7;
long long dp[MAXN];
int n;

int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp[j] = (dp[j] + dp[j - i]) % MOD;
    cout << dp[n] << endl;
    return 0;
}