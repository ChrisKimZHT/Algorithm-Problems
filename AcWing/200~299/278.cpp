#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N + 10);
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    vector<vector<int>> dp(N + 10, vector<int>(M + 10));
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0)
                dp[i][j] += dp[i - 1][j - a[i]];
        }
    }
    // for (int i = 1; i <= N; i++)
    //     for (int j = 1; j <= M; j++)
    //         cout << dp[i][j] << " \n"[j == M];
    cout << dp[N][M] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}