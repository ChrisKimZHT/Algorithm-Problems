#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5010;
long long N, M;
long long X[MAXN], Y[MAXN];
long long dp[MAXN][MAXN];
long long ans;

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> X[i];
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        Y[a] = b;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] + X[i] + Y[j];
        for (int j = 0; j < i; j++)
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    }
    for (int i = 0; i <= N;i++)
        ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}