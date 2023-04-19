#include <bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize(2)

using namespace std;

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> data(K + 1);
    for (int i = 1; i <= K; i++)
        cin >> data[i].first >> data[i].second;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= K; i++)
        for (int j = N; j >= data[i].first; j--)
            for (int k = M - 1; k >= data[i].second; k--)
                dp[j][k] = max(dp[j][k], dp[j - data[i].first][k - data[i].second] + 1);
    int ans1 = dp[N][M - 1], ans2 = M;
    while (ans2 > 0 && dp[N][ans2 - 1] == ans1)
        ans2--;
    cout << ans1 << ' ' << M - ans2 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}