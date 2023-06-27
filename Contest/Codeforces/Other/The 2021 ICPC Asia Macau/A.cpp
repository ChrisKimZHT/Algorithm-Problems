#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2)
                ans.push_back(a[i][j]);
            else
                ans.push_back(a[i][n - j - 1]);
        }
    }
    int cnt = 0;
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i - 1] < ans[i])
            cnt++;
        else
            cnt--;
    }
    if (cnt >= 0)
    {
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " \n"[i == 0];
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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