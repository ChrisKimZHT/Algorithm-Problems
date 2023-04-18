#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> arr(N + 10);
    arr[0] = INT32_MIN;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    vector<int> dp(N + 10);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < N; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
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