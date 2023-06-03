#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edge(n + 10);
    for (int i = 0; i < n - 1; i++)
        cin >> edge[i].first >> edge[i].second;
    vector<bool> st(n + 10);
    st[1] = true;
    int ans = 0;
    while (true)
    {
        ans++;
        for (int i = 0; i < n - 1; i++)
        {
            int &u = edge[i].first, &v = edge[i].second;
            if (!st[u] && st[v] || !st[v] && st[u])
                st[u] = st[v] = true;
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
            if (!st[i])
                flag = true;
        if (!flag)
            break;
    }
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