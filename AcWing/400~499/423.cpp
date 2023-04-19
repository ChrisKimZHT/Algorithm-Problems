#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int T, M;
    cin >> T >> M;
    vector<pair<int, int>> data(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> data[i].first >> data[i].second;
    vector<int> dp(T + 1);
    for (int i = 1; i <= M; i++)
        for (int j = T; j > 0; j--)
            if (j - data[i].first >= 0)
                dp[j] = max(dp[j], dp[j - data[i].first] + data[i].second);
    cout << dp[T] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}