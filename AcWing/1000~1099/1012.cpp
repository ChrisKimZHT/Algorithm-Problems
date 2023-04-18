#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> p(N + 10);
    for (int i = 1; i <= N; i++)
        cin >> p[i].first >> p[i].second;
    sort(p.begin() + 1, p.begin() + 1 + N);
    vector<int> dp(N + 10);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            if (p[j].second < p[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[i]);
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