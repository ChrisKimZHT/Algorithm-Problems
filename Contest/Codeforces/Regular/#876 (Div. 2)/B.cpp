#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pque;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pque.push({-a, b});
    }
    int ans = 0;
    while (pque.size())
    {
        auto now = -pque.top().first;
        for (int i = 0; i < now; i++)
        {
            if (pque.empty())
                break;
            auto t = pque.top();
            if (-t.first != now)
                break;
            pque.pop();
            ans += t.second;
        }
        while (pque.size() && -pque.top().first == now)
            pque.pop();
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