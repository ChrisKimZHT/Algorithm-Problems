/* #include <iostream>
#define endl '\n'

using namespace std;

const int MAXT = 1010, MAXB = 100010, MOD = 1e6;
int T, A, S, B;
int cnt[MAXT];
int dp[MAXT][MAXB];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> A >> S >> B;
    for (int i = 0; i < A; i++)
    {
        int t;
        cin >> t;
        cnt[t]++;
    }
    for (int i = 0; i <= T; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            if (j - cnt[i] - 1 >= 0)
                dp[i][j] = ((dp[i][j] - dp[i - 1][j - cnt[i] - 1]) % MOD + MOD) % MOD;
        }
    }
    int ans = 0;
    for (int i = S; i <= B; i++)
        ans = (ans + dp[T][i]) % MOD;
    cout << ans << endl;
    return 0;
} */

#include <iostream>
#define endl '\n'

using namespace std;

const int MAXT = 1010, MAXB = 100010, MOD = 1e6;
int T, A, S, B;
int cnt[MAXT];
int dp[2][MAXB];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> A >> S >> B;
    for (int i = 0; i < A; i++)
    {
        int t;
        cin >> t;
        cnt[t]++;
    }
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            dp[i % 2][j] = (dp[i % 2][j - 1] + dp[(i - 1) % 2][j]) % MOD;
            if (j - cnt[i] - 1 >= 0)
                dp[i % 2][j] = ((dp[i % 2][j] - dp[(i - 1) % 2][j - cnt[i] - 1]) % MOD + MOD) % MOD;
        }
    }
    int ans = 0;
    for (int i = S; i <= B; i++)
        ans = (ans + dp[T % 2][i]) % MOD;
    cout << ans << endl;
    return 0;
}