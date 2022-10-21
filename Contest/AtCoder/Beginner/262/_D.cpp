#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 110;
int N, a[MAXN];
int ans = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++) // 选i个数
    {
        vector dp(N + 1, vector(i + 1, vector<int>(i, 0)));
        dp[0][0][0] = 1;
        for (int j = 0; j < N; j++) // 前j+1个数
        {
            for (int k = 0; k <= i; k++) // 选k个数
            {
                for (int l = 0; l < i; l++) // 除i余l
                {
                    dp[j + 1][k][l] += dp[j][k][l];
                    dp[j + 1][k][l] %= MOD;
                    if (k != i)
                    {
                        dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
                        dp[j + 1][k + 1][(l + a[j]) % i] %= MOD;
                    }
                }
            }
        }
        ans += dp[N][i][0];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}