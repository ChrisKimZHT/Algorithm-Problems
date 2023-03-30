#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int get_ans(vector<int> &arr)
{
    vector<int> dp(arr.size());
    for (int i = 1; i < arr.size(); i++)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
    int ans = 0;
    for (int i = 1; i < arr.size(); i++)
        ans = max(ans, dp[i]);
    return ans;
}

void solve()
{
    int N;
    cin >> N;
    vector<int> h(N + 1);
    h[0] = INT32_MAX;
    for (int i = 1; i <= N; i++)
        cin >> h[i];
    int ans = get_ans(h);
    reverse(h.begin() + 1, h.end());
    ans = max(ans, get_ans(h));
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}