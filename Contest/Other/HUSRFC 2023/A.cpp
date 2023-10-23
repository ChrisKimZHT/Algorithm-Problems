#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 5e6 + 10;
int dp[MAXN];

void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    int y, n, m;
    cin >> y >> n >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    deque<int> dque;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        dque.push_back(i);
    }
    for (int i = n + 1; i <= y; i++)
    {
        while (dque.size() && dque.front() + n < i)
            dque.pop_front();
        for (int j = 0; j < m; j++)
            if (i % b[j] == 0)
                dp[i] = min(dp[i], dp[i / b[j]] + 1);
        dp[i] = min(dp[i], dp[dque.front()] + 1);
        while (dque.size() && dp[dque.back()] > dp[i])
            dque.pop_back();
        dque.push_back(i);
    }
    cout << dp[y] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}