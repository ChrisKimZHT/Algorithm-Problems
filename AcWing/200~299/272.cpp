#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N + 10), B(N + 10);
    vector<vector<int>> dp(N + 10, vector<int>(N + 10, 0));
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 1; i <= N; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (A[i] == B[j])
                dp[i][j] = max(dp[i][j], maxv);
            if (B[j] < A[i])
                maxv = max(maxv, dp[i - 1][j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(dp[N][i], ans);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}