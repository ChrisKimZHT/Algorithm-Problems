#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 10), nxt(n + 10);
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1])
            pre[i] = pre[i - 1];
        else
            pre[i] = i - 1;
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i + 1])
            nxt[i] = nxt[i + 1];
        else
            nxt[i] = i + 1;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << pre[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
    //     cout << nxt[i] << " \n"[i == n];
    vector<pair<int, int>> pv;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            pv.push_back({i, i});
        }
        else if (a[i] == 1)
        {
            pv.push_back({i, nxt[i]});
            pv.push_back({pre[i], i});
        }
        else // if (a[i] == 2)
        {
            pv.push_back({pre[i], nxt[i]});
        }
    }
    sort(pv.begin(), pv.end());
    int ans = 0, idx = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = -1, r = -1;
        for (; idx < pv.size(); idx++)
        {
            if (!(l == -1 || pv[idx].first <= i))
                break;
            l = pv[idx].first;
            r = pv[idx].second;
        }
        ans += max(0LL, l - i);
        ans++;
        i = r;
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