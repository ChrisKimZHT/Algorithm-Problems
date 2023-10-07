#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> st(n + 10);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> st[i];
        st[i] = '0' + st[i];
    }
    vector<vector<pair<int, int>>> cnt(n + 10, vector<pair<int, int>>(m + 10));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (st[i][j] == '#')
            {
                cnt[i][j].first = cnt[i - 1][j].first + 1;
                cnt[i][j].second = cnt[i][j - 1].second + 1;
                ans += cnt[i][j].first * cnt[i][j].first;
                ans += cnt[i][j].second * cnt[i][j].second;
            }
            else
            {
                cnt[i][j].first = cnt[i][j].second = 0;
            }
        }
    }
    cout << ans << endl;
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